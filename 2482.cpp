struct Solution {
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> oneRow(m), oneCol(n);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                oneRow[i] += grid[i][j];
                oneCol[j] += grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                grid[i][j] = (oneRow[i] + oneCol[j]) * 2 - m - n;
            }
        }
        return grid;
    }
};
