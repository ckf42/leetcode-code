struct Solution {
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                res += words[j].starts_with(words[i]) && words[j].ends_with(words[i]);
            }
        }
        return res;
    }
};
