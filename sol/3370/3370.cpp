#include <bit>

struct Solution {
    inline int smallestNumber(int n) {
        return (1 << (32 - countl_zero(static_cast<unsigned>(n)))) - 1;
    }
};
