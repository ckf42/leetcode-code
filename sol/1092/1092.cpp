struct Solution {
    string shortestCommonSupersequence(string &str1, string &str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i){
            memo[i][0] = i;
        }
        for (int j = 1; j <= n2; ++j){
            memo[0][j] = j;
        }
        for (int i = 0; i < n1; ++i){
            for (int j = 0; j < n2; ++j){
                if (str1[i] == str2[j]){
                    memo[i + 1][j + 1] = memo[i][j] + 1;
                } else {
                    memo[i + 1][j + 1] = min(memo[i][j + 1], memo[i + 1][j]) + 1;
                }
            }
        }
        int l = memo[n1][n2];
        string res(l, ' ');
        int wptr = l - 1, i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0){
            if (str1[i] == str2[j]){
                res[wptr--] = str1[i];
                --i;
                --j;
            } else if (memo[i + 1][j + 1] == memo[i][j + 1] + 1){
                res[wptr--] = str1[i--];
            } else {
                res[wptr--] = str2[j--];
            }
        }
        if (i >= 0){
            res.replace(0, i + 1, str1, 0, i + 1);
        }
        if (j >= 0){
            res.replace(0, j + 1, str2, 0, j + 1);
        }
        return res;
    }
};
