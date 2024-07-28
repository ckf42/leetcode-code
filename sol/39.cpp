struct Solution {
    void gen(int idx, int remain, vector<int> &prefix, vector<vector<int>> &res, vector<int> &cand){
        if (remain == 0){
            res.push_back(prefix);
            return;
        }
        if (idx == cand.size() || cand[idx] > remain){
            return;
        }
        this->gen(idx + 1, remain, prefix, res, cand);
        int x = cand[idx];
        int r = remain / x;
        for (int i = 1; i <= r; ++i){
            prefix.push_back(x);
            this->gen(idx + 1, remain - x * i, prefix, res, cand);
        }
        while (r-- > 0){
            prefix.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> prefix;
        this->gen(0, target, prefix, res, candidates);
        return res;
    }
};
