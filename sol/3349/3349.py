class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        if len(nums) < k * 2:
            return False
        prev = nums[0] + 1
        streak = 0
        prevIsValid = False
        for x in nums:
            if x <= prev:
                isValid = streak >= k
                if isValid and prevIsValid:
                    return True
                prevIsValid = isValid
                streak = 0
            streak += 1
            if streak >= k * 2:
                return True
            prev = x
        return streak >= k and prevIsValid
