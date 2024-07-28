struct Solution {
    bool ispal(int i, int j, vector<vector<char>> &rec, string &s){
        if (i > j){
            return true;
        }
        if (rec[i][j] == 2){
            if (s[i] != s[j]){
                rec[i][j] = 0;
            } else {
                rec[i][j] = this->ispal(i + 1, j - 1, rec, s);
            }
        }
        return rec[i][j] == 1;
    }
    int minCut(string &s) {
        int n = s.size();
        vector<vector<char>> rec(n, vector<char>(n, 2));
        for (int i = 0; i < n; ++i){
            rec[i][i] = 1;
        }
        if (this->ispal(0, n - 1, rec, s)){
            return 0;
        }
        vector<int> memo(n, n);
        memo[0] = 0;
        for (int i = 1; i < n; ++i){
            if (this->ispal(0, i, rec, s)){
                memo[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j){
                if (this->ispal(j + 1, i, rec, s)){
                    memo[i] = min(memo[i], memo[j] + 1);
                }
            }
        }
        return memo.back();
    }
};
