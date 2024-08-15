#include <algorithm>

struct Solution {
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        vector<int> rk(score.size());
        iota(rk.begin(), rk.end(), 0);
        sort(rk.begin(), rk.end(), [&score](int i, int j){return score[i] > score[j];});
        for (int idx = 0; idx < rk.size(); ++idx){
            int val = rk[idx];
            if (idx >= 3){
                res[val] = to_string(idx + 1);
            } else if (idx == 2) {
                res[val] = "Bronze Medal";
            } else if (idx == 1) {
                res[val] = "Silver Medal";
            } else {
                res[val] = "Gold Medal";
            }
        }
        return res;
    }
};
