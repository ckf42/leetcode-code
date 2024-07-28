struct Solution {
    inline bool isVowel(char c) {
        if (c >= 'a'){
            return (1065233 >> (c - 'a')) & 1;
        } else if (c >= 'A') {
            return (1065233 >> (c - 'A')) & 1;
        } else {
            return false;
        }
    }
    inline string reverseVowels(string &s) {
        int i = 0, j = s.size() - 1;
        while (true){
            while (i < j && !this->isVowel(s[i])){
                ++i;
            }
            while (i < j && !this->isVowel(s[j])){
                --j;
            }
            if (i >= j){
                break;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
