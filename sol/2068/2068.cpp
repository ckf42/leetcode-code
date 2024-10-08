struct Solution {
    inline bool checkAlmostEquivalent(string &word1, string &word2) {
        int f1[26] = {0}, f2[26] = {0};
        for (char c : word1){++f1[c - 'a'];}
        for (char c : word2){++f2[c - 'a'];}
        for (int i = 0; i < 26; ++i){
            if (abs(f1[i] - f2[i]) > 3){
                return false;
            }
        }
        return true;
    }
};
