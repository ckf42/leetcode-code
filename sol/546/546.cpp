struct Solution {
    using pr = pair<int, int>;
    using Memo_t = int[101][101][101];
    int dp(int i, int j, int k, vector<pr> &gp, Memo_t &memo){
        if (i > j){
            return 0;
        }
        if (memo[i][j][k] == -1){
            int p = (k + gp[i].second) * (k + gp[i].second) + this->dp(i + 1, j, 0, gp, memo);
            for (int m = i + 1; m <= j; ++m){
                if (gp[m].first != gp[i].first){
                    continue;
                }
                p = max(
                    p,
                    this->dp(i + 1, m - 1, 0, gp, memo) + this->dp(m, j, k + gp[i].second, gp, memo)
                );
            }
            memo[i][j][k] = p;
        }
        return memo[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<pr> gp;
        int prev = boxes[0], count = 0;
        for (int x : boxes){
            if (x != prev){
                gp.push_back({prev, count});
                prev = x;
                count = 0;
            }
            ++count;
        }
        gp.push_back({prev, count});
        int ngp = gp.size();
        Memo_t memo;
        for (int i = 0; i < ngp; ++i){
            for (int j = i; j < ngp; ++j){
                for (int k = 0; k < n; ++k){
                    memo[i][j][k] = -1;
                }
            }
        }
        return this->dp(0, ngp - 1, 0, gp, memo);
    }
};
