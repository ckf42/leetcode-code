class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        segend = 0
        maxreach = 0
        for i in range(n - 1):
            maxreach = max(maxreach, i + nums[i])
            if i == segend:
                res += 1
                segend = maxreach
        return res
