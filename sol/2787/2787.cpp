struct Solution {
    static constexpr int m = 1e9 + 7;
    inline int pow(int b, int expo){
        int res = 1;
        while (expo-- > 0){
            res *= b;
        }
        return res;
    }
    int numberOfWays(int n, int x) {
        vector<int> cand;
        for (int i = 1; ; ++i){
            int j = this->pow(i, x);
            if (j > n){
                break;
            }
            cand.push_back(j);
        }
        int l = cand.size();
        vector<int> memo(n + 1, 0);
        memo[0] = 1;
        for (int i = 0; i < l; ++i){
            for (int nn = n; nn >= cand[i]; --nn){
                memo[nn] = (memo[nn] + memo[nn - cand[i]]) % m;
            }
        }
        return memo[n];
    }
};
