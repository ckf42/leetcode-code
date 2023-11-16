#include <algorithm>

struct Solution {
    int countPalindromicSubsequence(const string &s) {
        vector<int> indices[26];
        for (int i = 0; i < s.size(); ++i){
            indices[s[i] - 'a'].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < 26; ++i){
            if (indices[i].size() < 2){
                continue;
            }
            if (indices[i].size() > 2){
                ++res;
            }
            for (int j = 0; j < 26; ++j){
                if (i == j){
                    continue;
                }
                if (lower_bound(indices[j].cbegin(), indices[j].cend(), indices[i].front())
                        != lower_bound(indices[j].cbegin(), indices[j].cend(), indices[i].back())){
                    ++res;
                }
            }
        }
        return res;
    }
};
