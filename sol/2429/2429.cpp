#include <numeric>

struct Solution {
    int minimizeXor(int num1, int num2) {
        int k = popcount(static_cast<unsigned>(num2)), l = popcount(static_cast<unsigned>(num1));
        int m = 1;
        while (k > l){
            while ((num1 & m) != 0){
                m <<= 1;
            }
            num1 ^= m;
            ++l;
        }
        m = 1;
        while (k < l){
            while ((num1 & m) == 0){
                m <<= 1;
            }
            num1 ^= m;
            --l;
        }
        return num1;
    }
};
