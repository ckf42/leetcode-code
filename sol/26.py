class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        w = 1
        for i in range(1, n):
            if nums[i] != nums[w - 1]:
                nums[w] = nums[i]
                w += 1
        return w
