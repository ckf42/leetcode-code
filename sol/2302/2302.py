class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        res = 0
        s = 0
        n = len(nums)
        partSum = 0
        for e in range(n):
            partSum += nums[e]
            while partSum * (e - s + 1) >= k:
                partSum -= nums[s]
                s += 1
            res += e - s + 1
        return res
