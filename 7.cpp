struct Solution {
    constexpr static int intmax = 2147483647;
    constexpr static int intmaxmul = 1000000000;
    
    constexpr inline int reverse(int x) {
        int lastDigit, rev;
        if (x < 0){
            if (x <= -this->intmaxmul){
                // c++: (-3) % 10 == -3
                lastDigit = -(x % 10);
                rev = this->reverse(-((x + lastDigit) / 10));
                if ((this->intmax - rev) / this->intmaxmul >= lastDigit){
                    return -this->intmaxmul * lastDigit - rev;
                } else {
                    return 0;
                }
            } else {
                return -this->reverse(-x);
            }
        }
        lastDigit = x % 10;
        x /= 10;
        int y = 0, mul = 1;
        while (x != 0){
            y *= 10;
            y += x % 10;
            x /= 10;
            mul *= 10;
        }
        if ((this->intmax - y) / mul >= lastDigit){
            return lastDigit * mul + y;
        } else {
            return 0;
        }
    }
};
