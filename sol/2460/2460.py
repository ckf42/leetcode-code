class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        wptr = 0
        prevEle = nums[0]
        for i in range(1, n):
            if nums[i] == prevEle:
                prevEle *= 2
                nums[i] = 0
            if prevEle != 0:
                res[wptr] = prevEle
                wptr += 1
            prevEle = nums[i]
        res[wptr] = prevEle
        return res
