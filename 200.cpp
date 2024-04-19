struct Solution {
    void floodfill(int i, int j, vector<vector<char>>& grid){
        if (grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '2';
        if (i > 0 && grid[i - 1][j] == '1'){
            floodfill(i - 1, j, grid);
        }
        if (j > 0 && grid[i][j - 1] == '1'){
            floodfill(i, j - 1, grid);
        }
        if (i < grid.size() - 1 && grid[i + 1][j] == '1'){
            floodfill(i + 1, j, grid);
        }
        if (j < grid.front().size() - 1 && grid[i][j + 1] == '1'){
            floodfill(i, j + 1, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size(), res = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1'){
                    ++res;
                    floodfill(i, j, grid);
                }
            }
        }
        return res;
    }
};
