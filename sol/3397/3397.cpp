struct Solution {
    int maxDistinctElements(vector<int>& nums, int k) {
        ranges::sort(nums);
        int res = 0, nextChoice = nums[0] - k - 1;
        for (int x : nums){
            if (x + k >= nextChoice){
                nextChoice = max(nextChoice, x - k) + 1;
                ++res;
            }
        }
        return res;
    }
};
