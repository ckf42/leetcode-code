struct Solution {
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0, buff, newBuff;
        vector<int> memo(matrix[0]);
        for (int j = 0; j < n; ++j){
            res += memo[j];
        }
        for (int i = 1; i < m; ++i){
            buff = memo[0];
            memo[0] = matrix[i][0];
            res += memo[0];
            for (int j = 1; j < n; ++j){
                newBuff = 0;
                if (matrix[i][j] == 1){
                    newBuff = min(buff, min(memo[j - 1], memo[j])) + 1;
                }
                buff = memo[j];
                memo[j] = newBuff;
                res += memo[j];
            }
        }
        return res;
    }
};
