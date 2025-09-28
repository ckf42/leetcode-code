struct Solution {
    int triangleNumber(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size(), res = 0;
        for (int k = 2; k < n; ++k){
            if (nums[k] < nums[0] + nums[1]){
                res += k * (k - 1) / 2;
                continue;
            }
            int i = 0;
            for (int j = k - 1; j > 0; --j){
                while (i < j && nums[i] <= nums[k] - nums[j]){
                    ++i;
                }
                if (i == j){
                    break;
                }
                res += j - i;
            }
        }
        return res;
    }
};
