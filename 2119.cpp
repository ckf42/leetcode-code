struct Solution {
    constexpr inline bool isSameAfterReversals(const int &num){
        return num == 0 || num % 10 != 0;
    }
};
