class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = [None] * len(nums)
        for i, n in enumerate(nums):
            res[i] = '1' if n[i] == '0' else '0'
        return ''.join(res)
