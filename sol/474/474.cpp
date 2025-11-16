struct Solution {
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        for (auto &s : strs){
            int a = 0;
            for (auto c : s){
                a += c == '0';
            }
            int b = s.size() - a;
            for (int i = m - a; i >= 0; --i){
                for (int j = n - b; j >= 0; --j){
                    memo[i + a][j + b] = max(memo[i + a][j + b], memo[i][j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= m; ++i){
            for (int j = 0; j <= n; ++j){
                res = max(res, memo[i][j]);
            }
        }
        return res;
    }
};
