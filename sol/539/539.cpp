struct Solution {
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> tps(n);
        for (int i = 0; i < n; ++i){
            string &s = timePoints[i];
            tps[i] = s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4] - '0' * 671;
        }
        ranges::sort(tps);
        int res = tps[0] + 1440 - tps[n - 1];
        for (int i = 0; i < n - 1; ++i){
            res = min(res, tps[i + 1] - tps[i]);
        }
        return res;
    }
};
