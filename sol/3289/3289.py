class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            if x < 0:
                x = -x - 1
            if nums[x] < 0:
                res.append(x)
            else:
                nums[x] = -nums[x] - 1
        return res
