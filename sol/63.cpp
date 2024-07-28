struct Solution {
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1){
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        vector<int> memo(n, 0);
        memo[0] = 1;
        for (int j = 1; j < n; ++j){
            if (obstacleGrid[0][j] == 1){
                break;
            }
            memo[j] = 1;
        }
        for (int i = 1; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (obstacleGrid[i][j] == 1){
                    memo[j] = 0;
                } else {
                    memo[j] += (j == 0 ? 0 : memo[j - 1]);
                }
            }
        }
        return memo.back();
    }
};
