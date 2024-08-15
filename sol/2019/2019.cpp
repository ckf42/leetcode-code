#include <unordered_set>

struct Solution {
    using sint = unordered_set<int>;
    int scoreOfStudents(string &s, vector<int>& answers) {
        int n = s.size(), corrAns = 0;
        int i = 0, m = (n + 1) / 2;
        while (i < n){
            int j = i + 1;
            while (j < n && s[j] != '+'){
                j += 2;
            }
            int prod = 1;
            for (int k = i; k < j; ++++k){
                prod *= s[k] - '0';
            }
            corrAns += prod;
            i = j + 1;
        }
        vector<vector<sint>> memo(m, vector<sint>(m));
        for (int i = 0; i < m; ++i){
            memo[i][i].insert(s[i << 1] - '0');
        }
        for (int l = 1; l < m; ++l){
            for (int i = 0; i < m - l; ++i){
                int j = i + l;
                for (int k = i; k < j; ++k){
                    for (int a : memo[i][k]){
                        for (int b : memo[k + 1][j]){
                            if (s[(k << 1) | 1] == '+'){
                                if (a + b <= 1000){
                                    memo[i][j].insert(a + b);
                                }
                            } else if (a * b <= 1000){
                                memo[i][j].insert(a * b);
                            }
                        }
                    }
                }
            }
        }
        vector<bool> msk(1001, false);
        for (int a : memo[0][n >> 1]){
            msk[a] = true;
        }
        int res = 0;
        for (int a : answers){
            if (msk[a]){
                res += a == corrAns ? 5 : 2;
            }
        }
        return res;
    }
};
