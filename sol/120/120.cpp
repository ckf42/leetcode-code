struct Solution {
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> memo(n);
        memo[0] = triangle[0][0];
        for (int i = 1; i < n; ++i){
            memo[i] = triangle[i][i] + memo[i - 1];
            for (int j = i - 1; j > 0; --j){
                memo[j] = triangle[i][j] + min(memo[j], memo[j - 1]);
            }
            memo[0] += triangle[i][0];
        }
        return ranges::min(memo);
    }
};
