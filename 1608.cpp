struct Solution {
    inline int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), idx = 0;
        for (int i = 0; i <= n; ++i){
            while (idx < n && nums[idx] < i){
                ++idx;
            }
            if (idx == n - i){
                return i;
            }
        }
        return -1;
    }
};
