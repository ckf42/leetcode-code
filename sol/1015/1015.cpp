#include <numeric>

struct Solution {
    int smallestRepunitDivByK(int k) {
        if (k == 1){
            return 1;
        }
        if (std::gcd(k, 10) != 1){
            return -1;
        }
        int n = 1, r = 1;
        while (r != 0){
            r = (r * 10 + 1) % k;
            ++n;
        }
        return n;
    }
};
