struct Solution {
    inline bool isVowel(char c){
        switch (c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), q = queries.size();
        vector<int> count(n + 1, 0), res(q);
        for (int i = 0; i < n; ++i){
            count[i + 1] = count[i] + (this->isVowel(words[i].front()) && this->isVowel(words[i].back()));
        }
        for (int i = 0; i < q; ++i){
            res[i] = count[queries[i].back() + 1] - count[queries[i].front()];
        }
        return res;
    }
};
