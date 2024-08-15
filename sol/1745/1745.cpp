struct Solution {
    bool checkPartitioning(string &s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n,  false));
        for (int i = 0; i < n; ++i){
            isPal[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i){
            isPal[i][i + 1] = s[i] == s[i + 1];
        }
        for (int l = 3; l <= n; ++l){
            for (int i = 0, j = l - 1; j < n; ++i, ++j){
                isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
            }
        }
        for (int i = 0; i < n - 2; ++i){
            if (!isPal[0][i]){
                continue;
            }
            for (int j = i + 1; j < n - 1; ++j){
                if (isPal[i + 1][j] && isPal[j + 1][n - 1]){
                    return true;
                }
            }
        }
        return false;
    }
};
