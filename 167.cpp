struct Solution {
    vector<int> twoSum(const vector<int>& nums, int target) {
        int i, j, n = nums.size(), sum;
        i = 0;
        j = n - 1;
        while (i < j){
            sum = nums[i] + nums[j];
            if (sum == target){
                return {i + 1, j + 1};
            } else if (sum < target){
                ++i;
            } else {
                --j;
            }
        }
        return {0, 0};
    }
};

