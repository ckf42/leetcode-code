class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        res = -1
        mini = nums[0]
        for x in nums[1:]:
            if x <= mini:
                mini = x
            else:
                res = max(res, x - mini)
        return res
