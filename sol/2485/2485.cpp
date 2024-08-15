#include <cmath>

struct Solution {
    int pivotInteger(int n) {
        int m = n * (n + 1) / 2;
        int s = static_cast<int>(sqrt(m));
        return (s * s == m ? s : -1);
    }
};
