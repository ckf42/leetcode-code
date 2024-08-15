struct Solution {
    int uniquePaths(int m, int n) {
        vector<int> memo(n, 1);
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                memo[j] += memo[j - 1];
            }
        }
        return memo.back();
    }
};
