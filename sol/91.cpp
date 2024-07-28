struct Solution {
    int numDecodings(const string &s) {
        if (s[0] == '0'){
            return 0;
        }
        vector<int> memo(s.size() + 1, 0);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i < s.size() + 1; ++i){
            if (s[i - 1] != '0'){
                memo[i] += memo[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && '0' <= s[i - 1] && s[i - 1] <= '6')){
                memo[i] += memo[i - 2];
            }
        }
        return memo.back();
    }
};
