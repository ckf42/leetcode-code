struct Solution {
    bool canBeValid(const string &s, const string &locked) {
        int n = s.size();
        if (n & 1){
            return false;
        }
        int upper = 0, lower = 0;
        for (int i = 0; i < n; ++i){
            if (locked[i] == '0'){
                ++upper; --lower;
            } else if (s[i] == '('){
                ++upper; ++lower;
            } else {
                --upper; --lower;
            }
            if (upper < 0){
                return false;
            }
            if (lower < 0){
                lower &= 1;
                if (upper < lower){
                    return false;
                }
            }
        }
        return lower == 0;
    }
};
