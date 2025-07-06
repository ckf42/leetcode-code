#include <bit>

struct Solution {
    inline char kthCharacter(int k) {
        return 'a' + popcount(static_cast<unsigned>(k - 1)) % 26;
    }
};
