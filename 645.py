class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        diff1 = n * (n + 1) // 2 - sum(nums)
        diff2 = n * (n + 1) * (2 * n + 1) // 6 - sum(x ** 2 for x in nums)
        missing = (diff2 // diff1 + diff1) // 2
        return [missing - diff1, missing]
