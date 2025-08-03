class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        firstIdx = [-1] * 30
        for i in range(n - 1, -1, -1):
            x = nums[i]
            m = 1
            idx = 0
            while x >= m:
                if x & m:
                    firstIdx[idx] = i
                m <<= 1
                idx += 1
            res[i] = max(i, max(firstIdx)) - i + 1
        return res
