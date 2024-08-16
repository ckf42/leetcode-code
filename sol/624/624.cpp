struct Solution {
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), res = -1, minval = arrays[0].front(), maxval = arrays[0].back();
        for (int i = 1; i < n; ++i){
            res = max(res, max(maxval - arrays[i].front(), arrays[i].back() - minval));
            minval = min(minval, arrays[i].front());
            maxval = max(maxval, arrays[i].back());
        }
        return res;
    }
};
