struct Solution {
    constexpr double myPow(double x, long n) {
        if (n == 0 || x == 1.0){
            return 1;
        }
        if (n < 0){
            n = -n;
            x = 1.0 / x;
        }
        double y = 1;
        while (n > 1){
            if (n & 1){
                y *= x;
                n ^= 1;
            }
            x *= x;
            n >>= 1;
        }
        return x * y;
    }
};
