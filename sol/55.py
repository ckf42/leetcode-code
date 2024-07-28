
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        minReach = n - 1
        for i in range(n - 2, -1, -1):
            if i + nums[i] >= minReach:
                minReach = i
        return minReach == 0
