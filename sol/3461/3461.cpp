struct Solution {
    bool hasSameDigits(string &s) {
        int n = s.size();
        for (char &c : s){
            c -= '0';
        }
        while (n-- > 2) {
            for (int i = 0; i < n; ++i){
                s[i] = (s[i] + s[i + 1]) % 10;
            }
        }
        return s[0] == s[1];
    }
};
