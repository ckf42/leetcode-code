struct Solution {
    using ll = long long;
    long long minEnd(int n, int x) {
        ll m = 1;
        --n;
        ll res = x;
        while (n != 0){
            if ((res & m) == 0){
                if (n & 1){
                    res |= m;
                }
                n >>= 1;
            }
            m <<= 1;
        }
        return res;
    }
};
