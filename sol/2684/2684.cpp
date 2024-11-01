struct Solution {
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), r = 0, w = 1;
        vector<bool> memo[2];
        memo[0].resize(m);
        memo[1].resize(m);
        memo[0].flip();
        for (int j = 0; j < n - 1; ++j){
            bool hasFeasible = false;
            ranges::fill(memo[w], false);
            for (int i = 0; i < m; ++i){
                if (!memo[r][i]){
                    continue;
                }
                if (i != 0 && grid[i][j] < grid[i - 1][j + 1]){
                    memo[w][i - 1] = true;
                    hasFeasible = true;
                }
                if (grid[i][j] < grid[i][j + 1]){
                    memo[w][i] = true;
                    hasFeasible = true;
                }
                if (i != m - 1 && grid[i][j] < grid[i + 1][j + 1]){
                    memo[w][i + 1] = true;
                    hasFeasible = true;
                }
            }
            if (!hasFeasible){
                return j;
            }
            r ^= 1;
            w ^= 1;
        }
        return n - 1;
    }
};
