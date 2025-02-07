struct Solution {
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, currSum = 0, prev = nums[0] - 1;
        for (int x : nums){
            if (x <= prev){
                currSum = 0;
            }
            currSum += x;
            res = max(res, currSum);
            prev = x;
        }
        return res;
    }
};
