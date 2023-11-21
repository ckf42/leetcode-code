struct Solution {
    int garbageCollection(const vector<string>& garbage, const vector<int>& travel) {
        int res = 0, travelTime = 0, lastTravelTimes[3] = {0, 0, 0};
        for (int i = 0; i < garbage.size(); ++i){
            const string &house = garbage[i];
            res += house.size();
            if (house.find('G') != string::npos){
                lastTravelTimes[0] = travelTime;
            }
            if (house.find('M') != string::npos){
                lastTravelTimes[1] = travelTime;
            }
            if (house.find('P') != string::npos){
                lastTravelTimes[2] = travelTime;
            }
            travelTime += (i < travel.size() ? travel[i] : 0);
        }
        return res + lastTravelTimes[0] + lastTravelTimes[1] + lastTravelTimes[2];
    }
};
