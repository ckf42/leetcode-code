struct Solution {
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()){
            return false;
        }
        int count[26] = {0};
        for (size_t i = 0; i < s.size(); ++i){
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        for (size_t i = 0; i < 26; ++i){
            if (count[i] != 0){
                return false;
            }
        }
        return true;
    }
};
