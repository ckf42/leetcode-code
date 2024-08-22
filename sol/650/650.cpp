struct Solution {
    inline int minSteps(int n) {
        if (n == 1){
            return 0;
        }
        int count = 1, buff = 0, res = 0;
        while (count < n){
            buff = count;
            count <<= 1;
            ++++res;
            while (n % count != 0){
                count += buff;
                ++res;
            }
        }
        return res;
    }
};
