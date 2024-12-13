class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        badCount = [0] * n
        for i in range(n - 1):
            badCount[i + 1] = badCount[i] + 1 - ((nums[i] ^ nums[i + 1]) & 1)
        q = len(queries)
        res = [False] * q
        for i, qr in enumerate(queries):
            res[i] = badCount[qr[0]] == badCount[qr[1]]
        return res
