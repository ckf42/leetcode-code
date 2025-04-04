struct Solution {
    using ll = long long;
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n == k || k == 1){
            return 0;
        }
        vector<ll> indexVal(n - 1);
        for (int i = 0; i < n - 1; ++i){
            indexVal[i] = weights[i] + weights[i + 1];
        }
        ranges::sort(indexVal);
        ll res = 0;
        for (int i = 0; i < k - 1; ++i){
            res += indexVal[n - 2 - i] - indexVal[i];
        }
        return res;
    }
};
