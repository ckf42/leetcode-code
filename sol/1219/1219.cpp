struct Solution {
    int dfs(
            int i, int j, vector<vector<int>> &grid,
            const int &m, const int &n){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return -1;
        }
        int ogval = grid[i][j], res = 0;
        grid[i][j] = 0;
        res = max(res, dfs(i - 1, j, grid, m, n));
        res = max(res, dfs(i + 1, j, grid, m, n));
        res = max(res, dfs(i, j - 1, grid, m, n));
        res = max(res, dfs(i, j + 1, grid, m, n));
        grid[i][j] = ogval;
        return res + ogval;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] != 0){
                    res = max(res, dfs(i, j, grid, m, n));
                }
            }
        }
        return res;
    }
};
