struct Solution {
    inline bool isPal(int i, int j, const string &s){
        while (i < j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }

    using seg = pair<int, int>;
    using part = vector<seg>;
    using collPart = vector<part>;

    vector<vector<string>> partition(const string &s) {
        int n = s.size();
        vector<int> occurIdx[26];
        for (int i = 0; i < n; ++i){
            occurIdx[s[i] - 'a'].push_back(i);
        }
        vector<int> prevOccur(n, -1);
        for (int i = 0; i < 26; ++i){
            for (int j = 1; j < occurIdx[i].size(); ++j){
                prevOccur[occurIdx[i][j]] = occurIdx[i][j - 1];
            }
        }
        vector<collPart> memo(n);
        memo[0].push_back({{make_pair(0, 1)}});
        for (int i = 1; i < n; ++i){
            for (int ptr = i; ptr != -1; ptr = prevOccur[ptr]){
                if (!isPal(ptr, i, s)){
                    continue;
                }
                if (ptr == 0){
                    memo[i].push_back({{make_pair(0, i + 1)}});
                } else {
                    for (part possibility: memo[ptr - 1]){
                        possibility.push_back({make_pair(ptr, i - ptr + 1)});
                        memo[i].push_back(possibility);
                    }
                }
            }
        }
        vector<vector<string>> res;
        for (part &p : memo[n - 1]){
            res.push_back({});
            for (seg &sg : p){
                res.back().push_back(s.substr(sg.first, sg.second));
            }
        }
        return res;
    }
};
