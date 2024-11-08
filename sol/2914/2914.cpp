struct Solution {
    int minChanges(string &s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++++i){
            res += s[i] != s[i + 1];
        }
        return res;
    }
};
