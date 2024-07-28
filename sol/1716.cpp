struct Solution {
    inline constexpr int totalMoney(int n) {
        int q = n / 7, r = n % 7;
        return r * (r + 1 + 2 * q) / 2 + (q != 0 ? 7 * q * (q + 7) / 2 : 0);
    }
};
