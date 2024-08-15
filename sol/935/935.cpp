#include <array>
#include <cstdint>

struct Solution {
    using ll = int64_t;
    using arr = array<array<ll, 10>, 10>;
    constexpr static int M = 1'000'000'007;
    const static vector<vector<int>> transitionList;

    void matmul(const arr x, arr &y){
        arr z = {0};
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){
                for (int k = 0; k < 10; ++k){
                    z[i][j] += (x[i][k] * y[k][j]) % this->M;
                    z[i][j] %= this->M;
                }
            }
        }
        y = z;
    }

    int knightDialer(int n) {
        if (n == 1){
            return 10;
        }
        n -= 1;
        arr x = {0}, y = {0};
        for (int i = 0; i < 10; ++i){
            for (int j : this->transitionList[i]){
                x[i][j] = 1;
            }
            y[i][i] = 1;
        }
        while (n > 1){
            if (n & 1){
                this->matmul(x, y);
            }
            this->matmul(x, x);
            n >>= 1;
        }
        this->matmul(x, y);
        ll res = 0;
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){
                res += y[i][j];
                res %= this->M;
            }
        }
        return res;
    }
};

const vector<vector<int>> Solution::transitionList = {
    {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
    {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
};
