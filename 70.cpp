struct Solution {
    inline constexpr int climbStairs(int n) {
        int a = 1, b = 1, c;
        for (int i = 0; i < n - 1; ++i){
            c = a;
            a = b;
            b += c;
        }
        return b;
    }
};
