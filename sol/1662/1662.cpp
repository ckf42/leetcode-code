struct Solution {
    bool arrayStringsAreEqual(const vector<string>& word1, const vector<string>& word2) {
        string s1, s2;
        for (const string &w1 : word1){
            s1 += w1;
        }
        for (const string &w2 : word2){
            s2 += w2;
        }
        return s1 == s2;
    }
};
