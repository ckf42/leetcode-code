struct Solution {
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int M = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(k, 0));
        int ptr = grid[0][0] % k;
        memo[0][ptr] = 1;
        for (int j = 1; j < n; ++j){
            ptr = (ptr + grid[0][j]) % k;
            memo[j][ptr] = 1;
        }
        vector<int> buff;
        for (int i = 1; i < m; ++i){
            buff = memo[0];
            for (int r = 0; r < k; ++r){
                memo[0][(r + grid[i][0]) % k] = buff[r];
            }
            for (int j = 1; j < n; ++j){
                buff = memo[j];
                for (int r = 0; r < k; ++r){
                    memo[j][(r + grid[i][j]) % k] = (memo[j - 1][r] + buff[r]) % M;
                }
            }
        }
        return memo[n - 1][0];
    }
};
