struct Solution {
    int maxScore(vector<int>& nums) {
        ranges::sort(nums, std::greater<int>{});
        long prefix = 0;
        for (int i = 0; i < nums.size(); ++i){
            prefix += nums[i];
            if (prefix <= 0){
                return i;
            }
        }
        return nums.size();
    }
};
