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
        for (int k = 1; k <= n1 + n2; ++k){
            for (int i = max(1, k - n2); i < min(n1 + 1, k); ++i){
                int j = k - i;
                if (str1[i - 1] == str2[j - 1]){
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                } else {
                    memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + 1;
                }
            }
        }
        int l = memo[n1][n2];
        string res;
        int i = n1, j = n2;
        while (i > 0 && j > 0){
            if (str1[i - 1] == str2[j - 1]){
                res.push_back(str1[--i]);
                --j;
            } else if (memo[i][j] == memo[i - 1][j] + 1){
                res.push_back(str1[--i]);
            } else {
                res.push_back(str2[--j]);
            }
        }
        while (i-- > 0){
            res.push_back(str1[i]);
        }
        while (j-- > 0){
            res.push_back(str2[j]);
        }
        ranges::reverse(res);
        return res;
    }
};
