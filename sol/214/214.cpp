struct Solution {
    string shortestPalindrome(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while (i < n){
            if (s[i] == s[j]){
                lps[i++] = ++j;
            } else if (j == 0){
                ++i;
            } else {
                j = lps[j - 1];
            }
        }
        i = 0;
        j = 0;
        while (i < n){
            if (s[n - 1 - i] == s[j]){
                ++i;
                ++j;
            } else if (j == 0){
                ++i;
            } else {
                j = lps[j - 1];
            }
        }
        return string(s.rbegin(), s.rbegin() + n - j) + s;
    }
};
