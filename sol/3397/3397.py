class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = 1
        nextChoice = nums[0] - k + 1
        for x in nums[1:]:
            if x + k >= nextChoice:
                nextChoice = max(nextChoice, x - k) + 1
                res += 1
        return res
