struct Solution {
    inline int isVowel(char &c) const {
        return (0x208222 >> (c & 0x1f)) & 1;
    }

    bool halvesAreAlike(string &s) {
        int n = s.size(), c = 0;
        for (int i = 0; i < n / 2; ++i){
            c += this->isVowel(s[i]);
        }
        for (int i = n / 2; i < n; ++i){
            c -= this->isVowel(s[i]);
        }
        return c == 0;
    }
};
