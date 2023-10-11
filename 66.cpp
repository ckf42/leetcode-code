struct Solution {
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::const_iterator ptr = digits.cbegin();
        while (ptr != digits.cend() && *ptr == 9){
            ++ptr;
        }
        if (ptr == digits.cend()){
            digits.resize(digits.size() + 1);
            digits[0] = 1;
            for (size_t i = 1; i < digits.size(); ++i){
                digits[i] = 0;
            }
        } else {
            ++digits.back();
            for (vector<int>::reverse_iterator rptr = digits.rbegin();
                 rptr != digits.rend() - 1;
                 ++rptr){
                if (*rptr == 10){
                    *rptr = 0;
                    ++*(rptr + 1);
                } else {
                    break;
                }
            }
        }
        return digits;
    }
};
