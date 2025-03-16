struct Solution {
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ranges::sort(ranks);
        ll s = 1, e = static_cast<ll>(ranks[0]) * cars * cars;
        while (s < e){
            ll m = s + (e - s) / 2;
            int remain = cars;
            for (int r : ranks){
                remain -= static_cast<int>(sqrt(m / r));
                if (remain <= 0){
                    break;
                }
            }
            if (remain <= 0){
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};
