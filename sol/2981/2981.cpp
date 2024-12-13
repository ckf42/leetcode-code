#include <unordered_map>

struct Solution {
    int maximumLength(string &s) {
        unordered_map<int, int> h;
        int n = s.size(), l = 0, r;
        while (l < n){
            r = l + 1;
            while (r < n && s[r] == s[l]){
                ++r;
            }
            for (int i = 1; i <= r - l; ++i){
                h[i * 26 + s[l] - 'a'] += r - l - i + 1;
            }
            l = r;
        }
        int res = -1;
        for (auto &pr : h){
            if (pr.second >= 3){
                res = max(res, pr.first / 26);
            }
        }
        return res;
    }
};
