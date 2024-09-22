struct Solution {
    inline int findKthNumber(int n, int k) {
        int val = 1;
        --k;
        while (k != 0){
            int subSize = 0;
            long a = val, b = val + 1;
            while (a <= n){
                subSize += min(static_cast<long>(n) + 1, b) - a;
                a *= 10;
                b *= 10;
            }
            if (k >= subSize){
                ++val;
                k -= subSize;
            } else {
                val *= 10;
                --k;
            }
        }
        return val;
    }
};
