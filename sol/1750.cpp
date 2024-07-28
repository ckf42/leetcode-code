struct Solution {
    int minimumLength(string &s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (j > i && s[i] == s[j]){
            char c = s[i];
            while (i <= j && s[i] == c){
                ++i;
            }
            while (i <= j && s[j] == c){
                --j;
            }
        }
        return j - i + 1;
    }
};
