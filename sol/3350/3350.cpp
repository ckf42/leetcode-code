struct Solution {
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res = 0, prev = nums[0] + 1, streak = 0, prevStreak = 0, maxStreak = 0;
        for (int x : nums){
            if (x <= prev){
                res = max(res, min(streak, prevStreak));
                maxStreak = max(maxStreak, streak);
                prevStreak = streak;
                streak = 0;
            }
            ++streak;
            prev = x;
        }
        maxStreak = max(maxStreak, streak);
        res = max(res, min(streak, prevStreak));
        return max(res, maxStreak / 2);
    }
};
