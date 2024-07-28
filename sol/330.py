class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        res = 0
        reach = 0
        ptr = 0
        while reach < n:
            if ptr < len(nums) and reach >= nums[ptr] - 1:
                reach += nums[ptr]
                ptr += 1
            else:
                reach += reach + 1
                res += 1
        return res
