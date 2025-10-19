class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        prev = nums[0] + 1
        res = 0
        streak = 0
        prevStreak = 0
        maxStreak = 0
        for x in nums:
            if x <= prev:
                res = max(res, min(streak, prevStreak))
                maxStreak = max(maxStreak, streak)
                prevStreak = streak
                streak = 0
            streak += 1
            prev = x
        maxStreak = max(maxStreak, streak)
        res = max(res, min(streak, prevStreak))
        return max(res, maxStreak // 2)
