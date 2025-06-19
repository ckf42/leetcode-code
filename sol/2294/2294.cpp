struct Solution {
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size(), res = 1, start = nums[0];
        for (int x : nums){
            if (x > start + k){
                ++res;
                start = x;
            }
        }
        return res;
    }
};
