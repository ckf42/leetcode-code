struct Solution {
    int numDistinct(const string &s, const string &t) {
        if (s.size() < t.size()){
            return 0;
        }
        if (s.size() == t.size()){
            return (s == t ? 1 : 0);
        }
        using ull = unsigned long long int;
        vector<ull> dp(s.size(), 0);
        dp[0] = (s[0] == t[0] ? 1 : 0);
        for (int i = 1; i < s.size(); ++i){
            dp[i] = dp[i - 1] + (s[i] == t[0] ? 1 : 0);
        }
        ull topleft, temp;
        for (int j = 1; j < t.size(); ++j){
            topleft = dp[j];
            dp[j] = (s[j] == t[j] ? dp[j - 1] : 0);
            for (int i = j + 1; i < s.size(); ++i){
                temp = topleft;
                topleft = dp[i];
                dp[i] = dp[i - 1] + (s[i] == t[j] ? temp : 0);
            }
        }
        return static_cast<int>(dp.back());
    }
};
