struct Solution {
    int numberOfWays(const string &corridor) {
        constexpr int M = 1e9 + 7;
        vector<int> plants;
        int lastGroupEnd = -1, plantCount;
        for (int i = 0; i < corridor.size(); ++i){
            if (corridor[i] == 'P'){
                continue;
            }
            if (lastGroupEnd == -2){
                lastGroupEnd = i;
            } else {
                plantCount = i - lastGroupEnd - 1;
                if (plantCount != 0){
                    plants.push_back(plantCount);
                }
                lastGroupEnd = -2;
            }
        }
        if (lastGroupEnd < 0){
            return 0;
        }
        int s = 0;
        if (corridor[s] == 'P'){
            ++s;
        }
        long long int res = 1;
        for (int i = s; i < plants.size(); ++i){
            res = (res * (plants[i] + 1)) % M;
        }
        return res;
    }
};
