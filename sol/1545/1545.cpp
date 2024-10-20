struct Solution {
    char findKthBit(int n, int k) {
        char flip = 0, res;
        int l = (1 << n) - 1, m;
        while (true){
            if (n == 1){
                res = '0';
                break;
            }
            m = (l >> 1) + 1;
            if (k == m){
                res = '1';
                break;
            } else if (k > m){
                flip ^= 1;
                k = l - k + 1;
            }
            --n;
            l = m - 1;
        }
        return res ^ flip;
    }
};
