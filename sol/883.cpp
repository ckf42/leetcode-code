struct Solution {
    inline int projectionArea(vector<vector<int>>& grid) {
        int sum = 0, n = grid.size(), r, c;
        for (int i = 0; i < n; ++i){
            r = 0;
            c = 0;
            for (int j = 0; j < n; ++j){
                sum += (grid[i][j] != 0);
                r = max(r, grid[i][j]);
                c = max(c, grid[j][i]);
            }
            sum += r + c;
        }
        return sum;
    }
};
