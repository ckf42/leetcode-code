struct Solution {
    bool sumOfNumberAndReverse(int num) {
        int rev, m;
        for (int i = num / 2; i <= num; ++i){
            rev = 0;
            m = i;
            while (m != 0){
                rev *= 10;
                rev += m % 10;
                m /= 10;
            }
            if (i + rev == num){
                return true;
            }
        }
        return false;
    }
};
