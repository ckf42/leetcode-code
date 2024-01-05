struct Solution {
    int maxScore(const string &s) {
        int z = 0, m = -s.size();
        for (int i = 0; i < s.size() - 1; ++i){
            if (s[i] == '0'){
                ++z;
            }
            m = max(m, z * 2 - i);
        }
        return m + s.size() - 1 - z - (s.back() == '0' ? 1 : 0);
    }
};
