struct Solution {
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), res = abs(nums.back() - nums.front());
        for (int i = 0; i < n - 1; ++i){
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
};
