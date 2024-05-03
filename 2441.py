class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        exists = set()
        maxval = -1
        for n in nums:
            exists.add(n)
            n = abs(n)
            if n in exists and -n in exists:
                maxval = max(maxval, n)
        return maxval
