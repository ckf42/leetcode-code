struct Solution {
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land.front().size(), r, b;
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (land[i][j] != 1){
                    continue;
                }
                r = i;
                while (r < m && land[r][j] == 1){
                    ++r;
                }
                b = j;
                while (b < n && land[i][b] == 1){
                    ++b;
                }
                for (int ii = i; ii < r; ++ii){
                    for (int jj = j; jj < b; ++jj){
                        land[ii][jj] = 2;
                    }
                }
                res.push_back({i, j, r - 1, b - 1});
            }
        }
        return res;
    }
};
