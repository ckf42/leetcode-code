struct Solution {
    using Memo_t = vector<array<array<int, 26>, 26>>;
    int dp(int i, char h, char t, Memo_t &memo, vector<string>& words){
        if (i == words.size()){
            return 0;
        }
        if (memo[i][h][t] == -1){
            memo[i][h][t] = max(
                this->dp(i + 1, h, words[i].back() - 'a', memo, words) + (t == words[i].front() - 'a'),
                this->dp(i + 1, words[i].front() - 'a', t, memo, words) + (h == words[i].back() - 'a')
            );
        }
        return memo[i][h][t];
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        Memo_t memo(n);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < 26; ++j){
                for (int k = 0; k < 26; ++k){
                    memo[i][j][k] = -1;
                }
            }
        }
        int res = 0;
        for (auto &w : words){
            res += w.size();
        }
        res -= this->dp(1, words[0].front() - 'a', words[0].back() - 'a', memo, words);
        return res;
    }
};
