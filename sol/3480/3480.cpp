struct Solution {
    using ll = long long;
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        for (auto &pr : conflictingPairs){
            if (pr[1] < pr[0]){
                swap(pr[0], pr[1]);
            }
        }
        ranges::sort(conflictingPairs, [](auto &v1, auto &v2){return v1[0] > v2[0];});
        int prIdx = 0, minB0 = n + 1, minB1 = n + 1, minBIdx = -1;
        ll total = 0;
        vector<ll> ignoreGain(m, 0);
        for (int i = n; i >= 1; --i){
            while (prIdx < m && conflictingPairs[prIdx][0] >= i){
                int b = conflictingPairs[prIdx][1];
                if (b < minB0){
                    minB1 = minB0;
                    minB0 = b;
                    minBIdx = prIdx;
                } else if (b < minB1){
                    minB1 = b;
                }
                ++prIdx;
            }
            total += minB0 - i;
            if (minBIdx != -1){
                ignoreGain[minBIdx] += minB1 - minB0;
            }
        }
        return total + ranges::max(ignoreGain);
    }
};
