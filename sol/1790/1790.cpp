struct Solution {
    bool areAlmostEqual(const string& s1, const string& s2) {
        size_t indices[2];
        size_t ptr = 0;
        for (size_t i = 0; i < s1.size(); ++i){
            if (s1[i] != s2[i]){
                if (ptr == 2){
                    return false;
                }
                indices[ptr++] = i;
            }
        }
        if (ptr < 2){
            return ptr == 0;
        } else {
            return s1[indices[0]] == s2[indices[1]] && s1[indices[1]] == s2[indices[0]];
        }
    }
};
