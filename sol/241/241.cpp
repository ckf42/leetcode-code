struct Solution {
    vector<int> diffWaysToCompute(string &expression) {
        vector<char> tokenized;
        char buff = 0;
        for (char c : expression){
            if ('0' <= c && c <= '9'){
                buff *= 10;
                buff += c - '0';
            } else {
                tokenized.push_back(buff);
                buff = 0;
                tokenized.push_back(c);
            }
        }
        tokenized.push_back(buff);
        int n = tokenized.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n));
        for (int i = 0; i < n; ++++i){
            memo[i][i].push_back(tokenized[i]);
        }
        for (int l = 3; l <= n; ++++l){
            for (int i = 0; i <= n - l; ++++i){
                int j = i + l - 1;
                for (int k = i + 1; k < j; ++++k){
                    for (int a : memo[i][k - 1]){
                        for (int b : memo[k + 1][j]){
                            switch (tokenized[k]){
                                case '+':
                                    memo[i][j].push_back(a + b);
                                    break;
                                case '-':
                                    memo[i][j].push_back(a - b);
                                    break;
                                case '*':
                                    memo[i][j].push_back(a * b);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
        }
        return memo[0][n - 1];
    }
};
