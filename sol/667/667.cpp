struct Solution {
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        if (k == 1){
            ranges::iota(res, 1);
            return res;
        }
        int l = (k + 1) >> 1;
        if (k & 1){
            for (int i = 0; i < l; ++i){
                res[i * 2] = k + 1 - i;
                res[i * 2 + 1] = i + 1;
            }
        } else {
            for (int i = 0; i < l; ++i){
                res[i * 2] = i + 1;
                res[k - i * 2 - 1] = i + l + 2;
            }
            res[k] = l + 1;
        }
        for (int i = k + 1; i < n; ++i){
            res[i] = i + 1;
        }
        return res;
    }
};
