struct Solution {
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (mat[i][j]){
                    ++r[i]; ++c[j];
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < m; ++i){
            if (r[i] != 1){
                continue;
            }
            for (int j = 0; j < n; ++j){
                if (c[j] == 1){
                    counter += mat[i][j];
                }
            }
        }
        return counter;
    }
};
