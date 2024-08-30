struct Solution {
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size(), res = 0, i = 0, j = 1;
        for (int k = 2; k < n; ++k){
            while (j < k && nums[j] < nums[k] - diff){
                ++j;
            }
            if (nums[j] > nums[k] - diff){
                continue;
            }
            while (i < j && nums[i] < nums[j] - diff){
                ++i;
            }
            if (nums[i] == nums[j] - diff){
                ++res;
            }
        }
        return res;
    }
};
