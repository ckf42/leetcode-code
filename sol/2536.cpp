struct Solution {
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> d(n, vector<int>(n, 0));
        for (auto &q : queries){
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            ++d[r1][c1];
            if (r2 < n - 1){
                --d[r2 + 1][c1];
            }
            if (c2 < n - 1){
                --d[r1][c2 + 1];
            }
            if (r2 < n - 1 && c2 < n - 1){
                ++d[r2 + 1][c2 + 1];
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 1; j < n; ++j){
                d[i][j] += d[i][j - 1];
            }
        }
        for (int j = 0; j < n; ++j){
            for (int i = 1; i < n; ++i){
                d[i][j] += d[i - 1][j];
            }
        }
        return d;
    }
};
