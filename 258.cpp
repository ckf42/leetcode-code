struct Solution {
    inline int addDigits(int num) {
        if (num == 0){
            return 0;
        }
        return (num + 8) % 9 + 1;
    }
};
