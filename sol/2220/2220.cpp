struct Solution {
    inline int minBitFlips(int start, int goal) {
        return popcount(static_cast<unsigned>(start ^ goal));
    }
};
