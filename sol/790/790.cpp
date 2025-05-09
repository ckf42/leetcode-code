struct Solution {
    static constexpr int M = 1e9 + 7;
    inline int numTilings(int n) {
        vector<long> memo = {1, 1, 2};
        memo.reserve(n + 1);
        for (int i = 3; i <= n; ++i){
            memo[i] = (memo[i - 1] * 2 + memo[i - 3]) % this->M;
        }
        return static_cast<int>(memo[n]);
    }
};
