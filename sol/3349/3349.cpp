struct Solution {
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (nums.size() < k * 2){
            return false;
        }
        int prev = nums[0] + 1, streak = 0;
        bool prevIsValid = false;
        for (int x : nums){
            if (x <= prev){
                bool isValid = streak >= k;
                if (isValid && prevIsValid){
                    return true;
                }
                prevIsValid = isValid;
                streak = 0;
            }
            if (++streak >= k * 2){
                return true;
            }
            prev = x;
        }
        return streak >= k && prevIsValid;
    }
};
