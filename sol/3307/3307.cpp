#include <bit>
#include <ranges>

struct Solution {
    using ull = unsigned long long;
    char kthCharacter(long long k, vector<int>& operations) {
        ull mask = 0;
        for (int x : operations | ranges::views::reverse){
            mask <<= 1;
            mask |= x;
        }
        return 'a' + popcount(mask & (k - 1)) % 26;
    }
};
