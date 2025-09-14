struct Solution {
    static inline bool isNoZero(int x){
        if (x == 0){
            return false;
        }
        while (x != 0){
            if (x % 10 == 0){
                return false;
            }
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a <= n / 2; ++a){
            int b = n - a;
            if (this->isNoZero(a) && this->isNoZero(b)){
                return {a, b};
            }
        }
        return {};
    }
};
