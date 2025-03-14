struct Solution {
    int numberOfSubstrings(string &s) {
        int res = 0, indices[3] = {-1, -1, -1}, n = s.size();
        for (int i = 0; i < n; ++i){
            indices[s[i] - 'a'] = i;
            res += ranges::min({indices[0], indices[1], indices[2]}) + 1;
        }
        return res;
    }
};
