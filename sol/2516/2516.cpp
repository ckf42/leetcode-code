struct Solution {
    int takeCharacters(string s, int k) {
        int n = s.size(), totals[3] = {0};
        for (char c : s){
            ++totals[c - 'a'];
        }
        if (totals[0] < k || totals[1] < k || totals[2] < k){
            return -1;
        }
        int res = -1, l = 0, counts[3] = {0}, idx;
        for (int r = 0; r < n; ++r){
            idx = s[r] - 'a';
            ++counts[idx];
            while (l <= r && counts[idx] > totals[idx] - k){
                --counts[s[l++] - 'a'];
            }
            res = max(res, r - l + 1);
        }
        return n - res;
    }
};
