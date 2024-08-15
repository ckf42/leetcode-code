struct Solution {
    static inline bool isalnum(char c){
        return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
    static inline char tolower(char c){
        if (c <= '9'){
            return c;
        }
        return c | 0x20;
    }
    bool isPalindrome(string &s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (true){
            while (i < n && !this->isalnum(s[i])){
                ++i;
            }
            while (j >= 0 && !this->isalnum(s[j])){
                --j;
            }
            if (i >= j){
                break;
            }
            if (this->tolower(s[i++]) != this->tolower(s[j--])){
                return false;
            }
        }
        return true;
    }
};
