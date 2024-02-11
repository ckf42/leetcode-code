struct Solution {
    int countSubstrings(string &s) {
        int n = s.size(), res = 0, i, j;
        for (int c = 0; c < n; ++c){
            i = j = c;
            while (i >= 0 && j < n && s[i] == s[j]){
                ++res;
                --i;
                ++j;
            }
            i = c, j = c + 1;
            while (i >= 0 && j < n && s[i] == s[j]){
                ++res;
                --i;
                ++j;
            }
        }
        return res;
    }
};
