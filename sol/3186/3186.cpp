struct Solution {
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        ranges::sort(power);
        vector<ll> vals, counts;
        int prev = power[0], count = 1, n = power.size();
        for (int i = 1; i < n; ++i){
            if (power[i] != prev){
                vals.push_back(prev);
                counts.push_back(count);
                prev = power[i];
                count = 0;
            }
            ++count;
        }
        vals.push_back(prev);
        counts.push_back(count);
        int m = vals.size();
        vector<ll> memo(m, 0);
        memo[0] = vals[0] * counts[0];
        for (int i = 1; i < m; ++i){
            ll p = vals[i] * counts[i];
            memo[i] = max(p, memo[i - 1]);
            if (vals[i - 1] < vals[i] - 2){
                memo[i] = max(memo[i], memo[i - 1] + p);
            } else if (i >= 2 && vals[i - 2] < vals[i] - 2){
                memo[i] = max(memo[i], memo[i - 2] + p);
            } else if (i >= 3){
                memo[i] = max(memo[i], memo[i - 3] + p);
            }
        }
        return memo.back();
    }
};
