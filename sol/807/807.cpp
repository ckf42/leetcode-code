struct Solution {
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> hor(n, 0), ver(n, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                hor[i] = max(hor[i], grid[i][j]);
                ver[j] = max(ver[j], grid[i][j]);
            }
        }
        int total = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                total += min(hor[i], ver[j]) - grid[i][j];
            }
        }
        return total;
    }
};
