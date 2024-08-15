struct Solution {
    static inline bool isVowel(char c){
        return (0x104111 >> (c - 'a')) & 1;
    }
    inline int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for (int i = left; i <= right; ++i){
            res += this->isVowel(words[i].front()) & this->isVowel(words[i].back());
        }
        return res;
    }
};
