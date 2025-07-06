struct Solution {
    int possibleStringCount(string_view word) {
        int n = word.size(), res = 1;
        for (int i = 1; i < n; ++i){
            if (word[i] == word[i - 1]){
                ++res;
            }
        }
        return res;
    }
};
