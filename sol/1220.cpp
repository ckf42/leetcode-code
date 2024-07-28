struct Solution {
    static constexpr int m = 1000000007;
    using ll = long long int;
    void matmul(const ll (&x)[5][5], ll (&y)[5][5]){
        ll z[5][5];
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                z[i][j] = 0;
                for (int k = 0; k < 5; ++k){
                    z[i][j] = (z[i][j] + (x[i][k] * y[k][j]) % this->m) % this->m;
                }
            }
        }
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                y[i][j] = z[i][j];
            }
        }
    }

    int countVowelPermutation(int n) {
        if (n == 1){
            return 5;
        }
        --n;
        ll y[5][5] = {{0}};
        for (int i = 0; i < 5; ++i){
            y[i][i] = 1;
        }
        ll x[5][5] = {{0, 1, 1, 0, 1}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 0}};
        while (n > 1){
            if (n & 1){
                this->matmul(x, y);
                n ^= 1;
            }
            this->matmul(x, x);
            n >>= 1;
        }
        this->matmul(x, y);
        ll sum = 0;
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                sum = (sum + y[i][j]) % this->m;
            }
        }
        return sum;
    }
};
