struct Solution {
    int dp(int i, int m, int n, int (&postSum)[101], int (&memo)[101][101]){
        int &res = memo[i][m];
        if (res == -1){
            if (i + m >= n){
                res = postSum[i];
            } else {
                for (int x = 1; x <= min(m * 2, n - i); ++x){
                    res = max(
                        res,
                        postSum[i] - this->dp(i + x, max(m, x), n, postSum, memo)
                    );
                }
            }
        }
        return res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int postSum[101] = {0};
        postSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i){
            postSum[i] = postSum[i + 1] + piles[i];
        }
        int memo[101][101];
        for (int i = 0; i < n; ++i){
            for (int m = 1; m <= n; ++m){
                memo[i][m] = -1;
            }
        }
        for (int m = 1; m <= n; ++m){
            memo[n][m] = 0;
        }
        return this->dp(0, 1, n, postSum, memo);
    }
};
