#include <vector>

struct Solution {
    string minRemoveToMakeValid(string s) {
        vector<int> unmatchedIdx;
        int dep = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                ++dep;
                unmatchedIdx.push_back(i);
            } else if (s[i] == ')'){
                if (dep == 0){
                    s[i] = 0;
                } else {
                    unmatchedIdx.pop_back();
                    --dep;
                }
            }
        }
        string res;
        int ptr = 0;
        for (int i = 0; i < s.size(); ++i){
            if (ptr < unmatchedIdx.size() && i == unmatchedIdx[ptr]){
                ++ptr;
            } else if (s[i] != 0){
                res += s[i];
            }
        }
        return res;
    }
};
