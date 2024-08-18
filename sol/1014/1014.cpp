struct Solution {
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), opt = values[0] - 1, res = values[0] + values[1] - 1;
        for (int i = 2; i < n; ++i){
            opt = max(opt, values[i - 1]) - 1;
            res = max(res, opt + values[i]);
        }
        return res;
    }
};
