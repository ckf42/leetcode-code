struct Solution {
    using dpArr = int[50][50][50];
    constexpr static int M = 1e9 + 7;

    int dp(int i, int j, int remainMoves, dpArr &memo, int &m, int &n){
        if (i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
        if (remainMoves < 0){
            return 0;
        }
        if (memo[i][j][remainMoves] == -1){
            memo[i][j][remainMoves] = (
                (dp(i - 1, j, remainMoves - 1, memo, m, n) + dp(i + 1, j, remainMoves - 1, memo, m, n)) % M 
                + (dp(i, j - 1, remainMoves - 1, memo, m, n) + dp(i, j + 1, remainMoves - 1, memo, m, n)) % M
            ) % M;
        }
        return memo[i][j][remainMoves];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dpArr arr;
        for (int i = 0; i < 50; ++i){
            for (int j = 0; j < 50; ++j){
               for (int k = 0; k < 50; ++k){
                   arr[i][j][k] = -1;
                }
            }
        }
        return dp(startRow, startColumn, maxMove - 1, arr, m, n);
    }
};
