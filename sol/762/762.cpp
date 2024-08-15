#include <bit>

struct Solution {
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (unsigned i = left; i <= right; ++i){
            res += (0xa28ac >> popcount(i)) & 1;
        }
        return res;
    }
};
