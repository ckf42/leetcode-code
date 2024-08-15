struct Solution {
    inline int jump(vector<int>& nums) {
        int n = nums.size(), res = 0, segend = 0, maxreach = 0;
        for (int i = 0; i < n - 1; ++i){
            maxreach = max(maxreach, i + nums[i]);
            if (i == segend){
                ++res;
                segend = maxreach;
            }
        }
        return res;
    }
};
