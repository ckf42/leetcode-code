struct Solution {
    vector<int> grayCode(int n) {
        int nn = 1 << n;
        vector<int> res(nn);
        for (int i = 0; i < nn; ++i){
            res[i] = i ^ (i >> 1);
        }
        return res;
    }
};
