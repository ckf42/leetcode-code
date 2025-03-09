struct Solution {
    static inline long powerMod(long base, int exponent, int modulo){
        long y = 1;
        while (exponent > 1){
            if (exponent & 1){
                y = (base * y) % modulo;
                exponent ^= 1;
            }
            base = (base * base) % modulo;
            exponent >>= 1;
        }
        return (base * y) % modulo;
    }
    static inline bool millerRabin(int n){
        int d = n - 1, s = 0;
        while ((d & 1) == 0){
            d >>= 1;
            ++s;
        }
        for (int a = 2; a <= 3; ++a){
            long x = powerMod(a, d, n);
            for (int i = 0; i < s; ++i){
                long y = powerMod(x, 2, n);
                if (y == 1 && x != 1 && x != n - 1){
                    return false;
                }
                x = y;
            }
            if (x != 1){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        if (left <= 2){
            if (right >= 3){
                return {2, 3};
            } else {
                return {-1, -1};
            }
        }
        if ((left & 1) == 0){
            ++left;
        }
        if ((right & 1) == 0){
            --right;
        }
        if (right - left <= 1){
            return {-1, -1};
        }
        vector<int> res = {-1, -1};
        int a = left;
        while (a < right && !millerRabin(a)){
            a += 2;
        }
        while (a < right){
            int b = a + 2;
            while (b <= right && !millerRabin(b)){
                b += 2;
            }
            if (b > right){
                break;
            }
            if (res[0] == -1 || b - a < res[1] - res[0]){
                res[0] = a;
                res[1] = b;
            }
            if (b - a == 2){
                break;
            }
            a = b;
        }
        return res;
    }
};
