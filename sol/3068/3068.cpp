struct Solution {
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size(), val, idx;
        long long res = 0;
        for (int &x : nums){
            res += x;
            x = (x ^ k) - x;
        }
        sort(nums.begin(), nums.end(), std::greater{});
        for (int i = 0; i < (n >> 1); ++i){
            idx = i << 1;
            val = nums[idx] + nums[idx + 1];
            if (val < 0){
                break;
            }
            res += val;
        }
        return res;
    }
};
