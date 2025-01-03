struct Solution {
    constexpr static int M = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, 0);
        memo[0] = 1;
        int res = 0;
        for (int i = 1; i <= high; ++i){
            if (i >= zero){
                memo[i] = (memo[i] + memo[i - zero]) % M;
            }
            if (i >= one){
                memo[i] = (memo[i] + memo[i - one]) % M;
            }
            if (i >= low){
                res = (res + memo[i]) % M;
            }
        }
        return res;
    }
};
