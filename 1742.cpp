struct Solution {
    static inline int f(int x){
        int res = 0;
        while (x != 0){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        int boxes[46] = {0}, res = 0;
        for (int i = lowLimit; i <= highLimit; ++i){
            ++boxes[this->f(i)];
        }
        for (int i = 1; i < 46; ++i){
            res = max(res, boxes[i]);
        }
        return res;
    }
};
