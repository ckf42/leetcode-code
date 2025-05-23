struct Solution {
    using ll = long long;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        ll res = 0;
        for (int i = 0; i < n; ++i){
            res += nums[i];
            nums[i] = (nums[i] ^ k) - nums[i];
        }
        ranges::sort(nums, std::greater{});
        for (int i = 0; i < n - 1; ++++i){
            if (nums[i] + nums[i + 1] > 0){
                res += nums[i] + nums[i + 1];
            } else {
                break;
            }
        }
        return res;
    }
};
