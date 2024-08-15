struct Solution {
    string longestPalindrome(const string &s) {
        short n = s.size(), maxi = 0, maxj = 0, i, j;
        for (short c = 0; c < n; ++c){
            i = c, j = c;
            while (i >= 0 && j < n && s[i] == s[j]){
                --i, ++j;
            }
            if (maxj - maxi < j - i - 2){
                maxi = i + 1, maxj = j - 1;
            }
            i = c, j = c + 1;
            while (i >= 0 && j < n && s[i] == s[j]){
                --i, ++j;
            }
            if (maxj - maxi < j - i - 2){
                maxi = i + 1, maxj = j - 1;
            }
        }
        return s.substr(maxi, maxj - maxi + 1);
    }
};
