class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            a = abs(nums[i])
            if nums[a - 1] > 0:
                nums[a - 1] *= -1
            else:
                res.append(a)
        return res
