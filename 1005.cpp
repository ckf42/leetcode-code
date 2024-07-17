struct Solution {
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size(), ptr = 0;
        while (ptr < n && k > 0){
            if (nums[ptr] >= 0){
                break;
            }
            nums[ptr++] *= -1;
            --k;
        }
        k &= 1;
        int s = reduce(nums.begin(), nums.end());
        if (k > 0){
            if (ptr == n){
                s -= nums.back() * 2;
            } else if (ptr > 0){
                s -= min(nums[ptr], nums[ptr - 1]) * 2;
            } else {
                s -= nums[0] * 2;
            }
        }
        return s;
    }
};
