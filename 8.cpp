struct Solution {
    inline int myAtoi(string &s) {
        int n = s.size(), ptr = 0, sgn = 1, val = 0, newd = 0;
        while (ptr < n && s[ptr] == ' '){
            ++ptr;
        }
        if (ptr == n){
            return 0;
        }
        if (s[ptr] == '-'){
            sgn = -1;
            ++ptr;
        } else if (s[ptr] == '+'){
            ++ptr;
        }
        while (ptr < n && '0' <= s[ptr] && s[ptr] <= '9'){
            newd = s[ptr] - '0';
            if (val > 214748364 || (val == 214748364 && newd >= (sgn == -1 ? 8 : 7))){
                return sgn == -1 ? -2147483648 : 2147483647;
            }
            val *= 10;
            val += newd;
            ++ptr;
        }
        return sgn * val;
    }
};
