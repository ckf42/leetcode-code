class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        M = 10 ** 9 + 7
        n = len(nums)
        nums.sort()
        res = 0
        r = n - 1
        for l in range(n):
            while r >= l and nums[l] + nums[r] > target:
                r -= 1
            if r < l:
                break
            res = (res + pow(2, r - l, M)) % M
        return res
