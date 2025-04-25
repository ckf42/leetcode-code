struct Solution {
    static constexpr array<int, 25> PrimeTable = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    static constexpr int M = 1e9 + 7;
    static constexpr array<int, 14> ModInverse = {0, 
        1, 500000004, 333333336, 250000002, 400000003,
        166666668, 142857144, 125000001, 111111112, 700000005,
        818181824, 83333334, 153846155};
    int idealArrays(int n, int maxValue) {
        int res = 0;
        for (int val = 1; val <= maxValue; ++val){
            long count = 1;
            int cand = val;
            for (int p : this->PrimeTable){
                int exponent = 0;
                while (cand % p == 0){
                    cand /= p;
                    ++exponent;
                }
                // count = (count * comb(n + exponent - 1, exponent)) % this->M;
                int m = n + exponent - 1, r = exponent;
                if (r * 2 > m){
                    r = m - r;
                }
                long comb = 1;
                if (r != 0){
                    comb = m;
                    for (int i = 2; i <= r; ++i){
                        comb = (comb * (m - i + 1)) % this->M;
                        comb = (comb * this->ModInverse[i]) % this->M;
                    }
                }
                count = (count * comb) % this->M;
                if (cand == 1){
                    break;
                }
            }
            if (cand != 1){
                count = (count * n) % this->M;
            }
            res = (res + count) % this->M;
        }
        return res;
    }
};
