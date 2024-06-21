struct Solution {
    inline bool judgeSquareSum(int c) {
        long a = 0, b = static_cast<int>(sqrt(c)), d;
        while (a <= b){
            d = a * a + b * b;
            if (d == c){
                return true;
            } else if (d > c){
                --b;
            } else {
                ++a;
            }
        }
        return false;
    }
};
