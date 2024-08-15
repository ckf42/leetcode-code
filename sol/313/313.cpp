#include <queue>

struct Solution {
    using pr = pair<long, int>;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1){
            return 1;
        }
        vector<long> memo(n, -1);
        vector<int> chainIdx(primes.size(), 0);
        memo[0] = 1;
        priority_queue<pr> h;
        for (int i = 0; i < primes.size(); ++i){
            h.push({-primes[i], i});
        }
        int w = 1;
        while (w < n){
            auto tpl = h.top();
            h.pop();
            int x = -tpl.first, pIdx = tpl.second;
            if (x != memo[w - 1]){
                memo[w++] = x;
            }
            h.push({-memo[++chainIdx[pIdx]] * primes[pIdx], pIdx});
        }
        return memo[n - 1];
    }
};
