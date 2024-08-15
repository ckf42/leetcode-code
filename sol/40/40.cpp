struct Solution {
    void backtrack(int remain, int idx, vector<int> &comb, vector<vector<int>> &res, vector<int> &nextIdx, vector<int> &candidates){
        if (remain == 0){
            res.push_back(comb);
            return;
        }
        if (idx == candidates.size() || candidates[idx] > remain){
            return;
        }
        comb.push_back(candidates[idx]);
        this->backtrack(remain - candidates[idx], idx + 1, comb, res, nextIdx, candidates);
        comb.pop_back();
        this->backtrack(remain, nextIdx[idx], comb, res, nextIdx, candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        int n = candidates.size();
        vector<int> nextIdx(n);
        for (int i = 0, j = 0; i < n; i = j){
            while (j < n && candidates[j] == candidates[i]){
                ++j;
            }
            for (int k = i; k < j; ++k){
                nextIdx[k] = j;
            }
        }
        vector<vector<int>> res;
        vector<int> comb;
        this->backtrack(target, 0, comb, res, nextIdx, candidates);
        return res;
    }
};
