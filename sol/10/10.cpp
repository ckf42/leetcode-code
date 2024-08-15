struct Solution {
    bool isMatch(string &s, string &p) {
        int ns = s.size(), np = p.size();
        vector<vector<bool>> memo(ns + 1, vector<bool>(np + 1, false));
        memo[ns][np] = true;
        for (int i = ns; i >= 0; --i){
            for (int j = np - 1; j >= 0; --j){
                bool m = i != ns && (p[j] == '.' || p[j] == s[i]);
                if (j < np - 1 && p[j + 1] == '*'){
                    memo[i][j] = memo[i][j + 2] || (m && memo[i + 1][j]);
                } else {
                    memo[i][j] = m && memo[i + 1][j + 1];
                }
            }
        }
        return memo[0][0];
    }
};
