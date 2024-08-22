struct Solution {
    inline int findComplement(int num) {
        int m = 1;
        while (m < num){
            m <<= 1;
            m |= 1;
        }
        return num ^ m;
    }
};
