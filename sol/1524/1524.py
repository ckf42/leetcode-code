class Solution:
    m = 10 ** 9 + 7
    def numOfSubarrays(self, arr: List[int]) -> int:
        memo = [0] * 2
        res = 0
        for x in arr:
            memo[0] += 1
            if x & 1:
                memo[0], memo[1] = memo[1], memo[0]
            res += memo[1]
        return res % self.m
