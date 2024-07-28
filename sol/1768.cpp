struct Solution {
    string mergeAlternately(const string &word1, const string &word2) {
        string res;
        for (size_t i = 0; i < min(word1.size(), word2.size()); ++i){
            res += word1[i];
            res += word2[i];
        }
        if (word1.size() >= word2.size()){
            res += word1.substr(word2.size());
        } else {
            res += word2.substr(word1.size());
        }
        return res;
    }
};struct Solution {
    string mergeAlternately(const string &word1, const string &word2) {
        string s;
        size_t s1 = word1.size(), s2 = word2.size(), i;
        for (i = 0; i < min(s1, s2); ++i){
            s += word1[i];
            s += word2[i];
        }
        if (s1 < s2){
            s += word2.substr(s1);
        } else {
            s += word1.substr(s2);
        }
        return s;
    }
};
