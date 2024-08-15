struct Solution {
    int mySqrt(int x) {
        if (x <= 1){
            return x;
        }
        if (x < 4){
            return 1;
        }
        int x0 = x, x1 = x >> 1;
        while (x0 > x1){
            x0 = x1;
            unsigned long temp = static_cast<unsigned long>(x0);
            temp *= temp;
            temp += static_cast<unsigned long>(x);
            x1 = static_cast<int>(temp / static_cast<unsigned long>(x0 << 1));
        }
        return x0;
    }
};
