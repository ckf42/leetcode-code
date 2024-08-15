struct Solution {
    int dp(int i, int j, int k, vector<int>& boxes, int (&memo)[101][101][101]){
        if (memo[i][j][k] == -1){
            int p = (k + 1) * (k + 1) + this->dp(i + 1, j, 0, boxes, memo);
            for (int m = i + 1; m <= j; ++m){
                if (boxes[m] == boxes[i]){
                    p = max(
                        p,
                        this->dp(m, j, k + 1, boxes, memo) + this->dp(i + 1, m - 1, 0, boxes, memo));
                }
            }
            memo[i][j][k] = p;
        }
        return memo[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int memo[101][101][101];
        for (int i = 0; i <= n; ++i){
            for (int j = 0; j <= n; ++j){
                for (int k = 0; k <= n; ++k){
                    memo[i][j][k] = i > j ? 0 : -1;
                }
            }
        }
        return this->dp(0, n - 1, 0, boxes, memo);
    }
};
