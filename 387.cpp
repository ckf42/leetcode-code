struct Solution {
    int firstUniqChar(string &s) {
        int indices[26];
        for (int i = 0; i < 26; ++i){
            indices[i] = -1;
        }
        for (int i = 0; i < s.size(); ++i){
            if (indices[s[i] - 'a'] == -1){
                indices[s[i] - 'a'] = i;
            } else if (indices[s[i] - 'a'] >= 0){
                indices[s[i] - 'a'] = -2;
            }
        }
        int res = s.size();
        for (int i = 0; i < 26; ++i){
            if (indices[i] >= 0){
                res = min(res, indices[i]);
            }
        }
        return res == s.size() ? -1 : res;
    }
};
