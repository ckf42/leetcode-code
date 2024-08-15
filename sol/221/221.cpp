struct Solution {
    int maximalSquare(const vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.front().size(), maxside = 0, leftup, temp;
        vector<int> memo(n, 0);
        for (int j = 0; j < n; ++j){
            memo[j] = (matrix[0][j] == '1' ? 1 : 0);
            maxside = max(maxside, memo[j]);
        }
        for (int i = 1; i < m; ++i){
            leftup = memo[0];
            memo[0] = (matrix[i][0] == '1' ? 1 : 0);
            maxside = max(maxside, memo[0]);
            for (int j = 1; j < n; ++j){
                temp = leftup;
                leftup = memo[j];
                memo[j] = (matrix[i][j] == '1' ? min(min(memo[j - 1], memo[j]), temp) + 1 : 0);
                maxside = max(maxside, memo[j]);
            }
        }
        return maxside * maxside;
    }
};
