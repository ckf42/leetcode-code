struct Solution {
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        ranges::sort(nums);
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        while (l < r){
            int m = (l + r) / 2, c = 0;
            for (int i = 0, j = 1; i < n - 1; ++i){
                while (j < n && nums[j] - nums[i] <= m){
                    ++j;
                }
                c += j - i - 1;
            }
            if (c < k){
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
