struct Solution {
    int numsBelow(int ub, vector<int> &nums){
        if (ub < 0){
            return 0;
        }
        int res = 0, subsum = 0, e = 0;
        for (int s = 0; s < nums.size(); ++s){
            while (e < nums.size() && subsum + nums[e] <= ub){
                subsum += nums[e++];
            }
            res += e - s;
            subsum -= nums[s];
        }
        return res;
    }
    inline int numSubarraysWithSum(vector<int>& nums, int goal) {
        return this->numsBelow(goal, nums) - this->numsBelow(goal - 1, nums);
    }
};
