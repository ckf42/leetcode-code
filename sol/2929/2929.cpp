struct Solution {
    using ll = long long;
    long long distributeCandies(int n, int limit) {
        if (n > limit * 3){
            return 0;
        } else if (n < limit){
            return static_cast<ll>(n + 1) * (n + 2) / 2;
        } else if (n < limit * 2){
            return (static_cast<ll>(limit + 2) * limit * 3 - static_cast<ll>(n * 2 - limit * 3) * static_cast<ll>(n * 2 - limit * 3)) / 4 + 1;
        }
        ll k = n - limit * 3 - 2;
        return k * (k + 1) / 2;
    }
};
