struct Solution {
    int maxCoins(vector<int>& nums) {
        vector<int> ele(1, 1);
        for (int x : nums){
            if (x != 0){
                ele.push_back(x);
            }
        }
        ele.push_back(1);
        int n = ele.size() - 2;
        if (n == 1){
            return ele[1];
        }
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < n; ++i){
            memo[i + 1][i + 1] = ele[i] * ele[i + 1] * ele[i + 2];
        }
        for (int l = 2; l <= n; ++l){
            for (int i = 0; i <= n - l; ++i){
                int j = i + l - 1;
                for (int k = i; k <= j; ++k){
                    memo[i + 1][j + 1] = max(
                        memo[i + 1][j + 1],
                        memo[i + 1][k] + memo[k + 2][j + 1] + ele[i] * ele[k + 1] * ele[j + 2]
                    );
                }
            }
        }
        return memo[1][n];
    }
};
