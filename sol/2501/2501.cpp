struct Solution {
    int longestSquareStreak(vector<int>& nums) {
        ranges::sort(nums);
        const auto indeterRange = ranges::unique(nums);
        nums.erase(indeterRange.begin(), indeterRange.end());
        vector<int> memo(nums.back() + 1, 0);
        int res = 1;
        for (int x : nums){
            int q = static_cast<int>(sqrt(x));
            if (q * q != x){
                memo[x] = 1;
                continue;
            }
            memo[x] = memo[q] + 1;
            res = max(res, memo[x]);
        }
        return (res == 1) ? -1 : res;
    }
};
