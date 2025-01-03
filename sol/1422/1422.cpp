struct Solution {
    int maxScore(const string &s) {
        int z = 0, m = -1;
        for (int i = 0; i < s.size() - 1; ++i){
            z += s[i] == '0';
            m = max(m, z * 2 - i);
        }
        return m + s.size() - 1 - z - (s.back() == '0');
    }
};
