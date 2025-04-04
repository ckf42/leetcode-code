struct Solution {
    using ll = long long;
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> memo(n, 0);
        memo[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i){
            int j = i + questions[i][1] + 1;
            memo[i] = max(memo[i + 1], questions[i][0] + (j < n ? memo[j] : 0));
        }
        return memo[0];
    }
};
