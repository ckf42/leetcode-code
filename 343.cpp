struct Solution {
    constexpr static int precomp[] = {1, 2, 4, 6, 9, 12, 18, 27, 36};
    constexpr int integerBreak(const int n) const {
        if (n < 10){
            return precomp[n - 2];
        }
        int q = (n - 7) / 3, prod = 1, y = 1, x = 3;
        while (q > 1){
            if (q & 1){
                y *= x;
                --q;
            }
            x *= x;
            q /= 2;
        }
        return x * y * precomp[(n - 1) % 3 + 5];
    }
};
