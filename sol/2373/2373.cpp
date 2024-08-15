struct Solution {
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 1; i < n - 1; ++i){
            for (int j = 1; j < n - 1; ++j){
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i - 1][j - 1]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i - 1][j]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i - 1][j + 1]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i][j - 1]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i][j]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i][j + 1]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i + 1][j - 1]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i + 1][j]);
                res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i + 1][j + 1]);
            }
        }
        return res;
    }
};
