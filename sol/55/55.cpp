struct Solution {
    inline bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = n - 1;
        for (int i = n - 2; i >= 0; --i){
            if (i + nums[i] >= m){
                m = i;
            }
        }
        return m == 0;
    }
};
