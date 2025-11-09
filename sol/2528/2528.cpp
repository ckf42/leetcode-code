struct Solution {
    using ll = long long;
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> arr(n + 1, 0);
        ll s = -1, e = k + 1;
        for (int i = 0; i < n; ++i){
            int v = stations[i];
            arr[max(0, i - r)] += v;
            arr[min(n, i + r + 1)] -= v;
            if (s == -1 || s > v) {
                s = v;
            }
            e += v;
        }
        while (s < e){
            ll m = s + (e - s) / 2, val = 0, remain = k;
            bool feasible = true;
            vector<ll> diff{arr};
            for (int i = 0; i < n; ++i){
                val += diff[i];
                if (val >= m){
                    continue;
                }
                ll x = m - val;
                if (x > remain){
                    feasible = false;
                    break;
                } else {
                    val += x;
                    remain -= x;
                    diff[min(n, i + r * 2 + 1)] -= x;
                }
            }
            if (feasible){
                s = m + 1;
            } else {
                e = m;
            }
        }
        return e - 1;
    }
};
