struct Solution {
    constexpr int numSquares(int n) {
        int sqrtn = static_cast<int>(std::sqrt(n));
        if (sqrtn * sqrtn == n){
            return 1;
        }
        int m, j;
        for (int i = 1; i <= sqrtn; ++i){
            m = n - i * i;
            j = static_cast<int>(std::sqrt(m));
            if (j * j == m){
                return 2;
            }
        }
        m = n;
        while((m & 3) == 0){
            m >>= 2;
        }
        if ((m & 7) != 7){
            return 3;
        } else {
            return 4;
        }
    }
};
