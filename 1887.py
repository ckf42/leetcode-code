class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        adder = 0
        currEle = nums[0]
        res = 0
        for n in nums:
            if n != currEle:
                adder += 1
                currEle = n
            res += adder
        return res
