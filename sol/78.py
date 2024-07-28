class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        for i in range(len(nums) + 1):
            yield from itertools.combinations(nums, i)
