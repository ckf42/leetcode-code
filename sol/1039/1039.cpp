struct Solution {
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n == 3){
            return values[0] * values[1] * values[2];
        }
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n - 2; ++i){
            memo[i][i + 2] = values[i] * values[i + 1] * values[i + 2];
        }
        for (int l = 3; l < n; ++l){
            for (int i = 0; i < n - l; ++i){
                int p = values[i] * values[i + l];
                memo[i][i + l] = memo[i][i + 1] + memo[i + 1][i + l] + p * values[i + 1];
                for (int j = i + 2; j < i + l; ++j){
                    memo[i][i + l] = min(memo[i][i + l], memo[i][j] + memo[j][i + l] + p * values[j]);
                }
            }
        }
        return memo[0][n - 1];
    }
};
