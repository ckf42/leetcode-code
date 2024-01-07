struct Solution {
    int numberOfArithmeticSlices(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2){
            return 0;
        }
        int res = 0, prev = 0, prevDiff = nums[1] - nums[0], val, currDiff;
        for (int i = 2; i < n; ++i){
            currDiff = nums[i] - nums[i - 1];
            val = 0;
            if (currDiff == prevDiff){
                val = prev + 1;
            }
            res += val;
            prev = val;
            prevDiff = currDiff;
        }
        return res;
    }
};
