struct Solution {
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()){
            return vector<vector<int>>();
        }
        vector<vector<int>> res(m);
        int idx = 0;
        for (int i = 0; i < m; ++i){
            res[i] = vector<int>(original.begin() + idx, original.begin() + idx + n);
            idx += n;
        }
        return res;
    }
};
