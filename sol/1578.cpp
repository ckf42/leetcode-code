struct Solution {
    int minCost(const string &colors, const vector<int>& neededTime) {
        int totalTime = 0;
        int s = 0, e, maxVal;
        while (s < colors.size()){
            e = s + 1;
            maxVal = neededTime[s];
            totalTime += maxVal;
            while (e < colors.size() && colors[s] == colors[e]){
                maxVal = max(maxVal, neededTime[e]);
                totalTime += neededTime[e];
                ++e;
            }
            totalTime -= maxVal;
            s = e;
        }
        return totalTime;
    }
};
