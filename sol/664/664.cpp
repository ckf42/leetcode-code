struct Solution {
    using Memo_t = int[101][101];
    int dp(int i, int j, string &gp, Memo_t &memo){
        if (i > j){
            return 0;
        }
        if (memo[i][j] == -1){
            int p = 1 + this->dp(i + 1, j, gp, memo);
            for (int k = i + 1; k <= j; ++k){
                if (gp[k] != gp[i]){
                    continue;
                }
                p = min(
                    p,
                    this->dp(k + 1, j, gp, memo) + this->dp(i, k - 1, gp, memo)
                );
            }
            memo[i][j] = p;
        }
        return memo[i][j];
    }
    int strangePrinter(string &s) {
        string gp(1, s[0]);
        for (int i = 1; i < s.size(); ++i){
            if (s[i] != gp.back()){
                gp += s[i];
            }
        }
        int ngp = gp.size();
        Memo_t memo;
        for (int i = 0; i < ngp; ++i){
            for (int j = i; j < ngp; ++j){
                memo[i][j] = -1;
            }
        }
        return this->dp(0, ngp - 1, gp, memo);
    }
};
