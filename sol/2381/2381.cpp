struct Solution {
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffs(n + 1, 0);
        for (auto &r : shifts){
            int c = r[2] * 2 - 1;
            diffs[r[0]] += c;
            diffs[r[1] + 1] -= c;
        }
        diffs[0] = (diffs[0] % 26 + 26) % 26;
        for (int i = 1; i <= n; ++i){
            diffs[i] = ((diffs[i] + diffs[i - 1]) % 26 + 26) % 26;
        }
        for (int i = 0; i < n; ++i){
            s[i] = (s[i] - 'a' + diffs[i]) % 26 + 'a';
        }
        return s;
    }
};
