class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i, x in enumerate(nums):
            prefix[i + 1] = prefix[i] + x
        total = prefix[n]
        return sum(
            2 - a
            for i in range(n)
            if nums[i] == 0 and (a := abs(total - prefix[i] * 2)) <= 1
        )
