struct Solution {
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int l = m, r = -1, u = n, d = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 1){
                    u = min(u, i);
                    d = i;
                    l = min(l, j);
                    r = max(r, j);
                }
            }
        }
        return (d - u + 1) * (r - l + 1);
    }
};
