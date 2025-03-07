struct Solution {
    inline long long coloredCells(int n) {
        long long nn = static_cast<long long>(n);
        return nn * (nn - 1) * 2 + 1;
    }
};
