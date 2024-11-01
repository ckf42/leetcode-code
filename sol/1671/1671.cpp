struct Solution {
    void lis(
            vector<int> &nums,
            int n,
            vector<int> &memo,
            vector<int> &m){
        m[0] = nums[0];
        int ptr = 1;
        memo[0] = 1;
        for (int i = 1; i < n; ++i){
            if (nums[i] > m[ptr - 1]){
                m[ptr++] = nums[i];
                memo[i] = ptr;
            } else {
                int ip = lower_bound(m.begin(), m.begin() + ptr, nums[i]) - m.begin();
                m[ip] = nums[i];
                memo[i] = ip + 1;
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> lisLen(n, 1), ldsLen(n, 1), m(n);
        this->lis(nums, n, lisLen, m);
        ranges::reverse(nums);
        this->lis(nums, n, ldsLen, m);
        for (int i = 0, j = n - 1; i < n; ++i, --j){
            if (lisLen[i] > 1 && ldsLen[j] > 1){
                res = max(res, lisLen[i] + ldsLen[j] - 1);
            }
        }
        return n - res;
    }
};
