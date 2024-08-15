struct Solution {
    inline constexpr bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return (sx == fx && sy == fy) ? (t != 1) : (max(abs(sx - fx), abs(sy - fy)) <= t);
    }
};
