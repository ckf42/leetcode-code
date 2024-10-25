#include <unordered_map>

struct Solution {
    void backtrack(int idx, unordered_map<string, bool> &oldSubstrs, int count, string &s, int &res){
        if (idx == s.size()){
            res = max(res, count);
            return;
        }
        for (int i = idx + 1; i <= s.size(); ++i){
            string substr = s.substr(idx, i - idx);
            if (!oldSubstrs[substr]){
                oldSubstrs[substr] = true;
                this->backtrack(i, oldSubstrs, count + 1, s, res);
                oldSubstrs[substr] = false;
            }
        }
    }
    int maxUniqueSplit(string &s) {
        int res = 0;
        unordered_map<string, bool> oldSubstrs;
        this->backtrack(0, oldSubstrs, 0, s, res);
        return res;
    }
};
