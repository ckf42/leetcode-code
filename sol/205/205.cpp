struct Solution {
    bool isIsomorphic(const string &s, const string &t) {
        char mapping[256] = {0};
        bool used[256] = {0};
        for (int i = 0; i < s.size(); ++i){
            if (mapping[s[i]] == 0 && !used[t[i]]){
                mapping[s[i]] = t[i];
                used[t[i]] = true;
            } else if (mapping[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
