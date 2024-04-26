#include <algorithm>
#include <array>

struct Solution {
    int longestIdealString(string &s, int k) {
        array<int, 26> memo;
        for (auto c : s){
            c -= 'a';
            int temp = 0;
            for (int i = max(0, c - k); i < min(26, c + k + 1); ++i){
                temp = max(temp, memo[i]);
            }
            memo[c] = temp + 1;
        }
        return *max_element(memo.begin(), memo.end());
    }
};
