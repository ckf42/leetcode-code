struct Solution {
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        for (int j = 1; j < n; ++j){
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; ++i){
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < n; ++j){
                grid[i][j] += min(grid[i][j - 1] , grid[i - 1][j]);
            }
        }
        return grid.back().back();
    }
};
