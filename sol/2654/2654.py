from math import gcd

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if 1 in nums:
            return n - nums.count(1)
        minLen = n
        g = nums[0]
        for j in range(1, n):
            g = gcd(g, nums[j])
            if g == 1:
                minLen = j + 1
                break
        if g != 1:
            return -1
        for i in range(1, n):
            g = nums[i]
            for j in range(i + 1, n):
                g = gcd(g, nums[j])
                if g == 1:
                    minLen = min(minLen, j + 1 - i)
                    break
        return minLen + n - 2
