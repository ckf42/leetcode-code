struct Solution {
    inline int appendCharacters(const string &s, const string &t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()){
            if (s[i++] == t[j]){
                ++j;
            }
        }
        return t.size() - j;
    }
};
