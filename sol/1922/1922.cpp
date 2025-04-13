struct Solution {
    using ll = long long;
    static constexpr ll m = 1e9 + 7;
    int countGoodNumbers(long long n) {
        ll res = 1;
        if (n & 1){
            res = 5;
        }
        n >>= 1;
        if (n == 0){
            return res;
        }
        ll x = 20;
        while (n > 1){
            if (n & 1){
                res = (res * x) % this->m;
            }
            x = (x * x) % this->m;
            n >>= 1;
        }
        return (x * res) % this->m;
    }
};
