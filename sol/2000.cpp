struct Solution {
    inline string reversePrefix(string &word, char ch) {
        size_t idx = word.find(ch);
        if (idx != string::npos){
            reverse(word.begin(), word.begin() + idx + 1);
        }
        return word;
    }
};
