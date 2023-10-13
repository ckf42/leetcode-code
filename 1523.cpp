struct Solution {
    constexpr int countOdds(int low, int high) {
        return (high + 2 - (low | 1)) >> 1;
    }
};
