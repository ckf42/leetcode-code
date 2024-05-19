class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        xorinc = [(x ^ k) - x for x in nums]
        xorinc.sort(reverse=True)
        res = sum(nums)
        for i in range(n // 2):
            inc = xorinc[i * 2] + xorinc[i * 2 + 1]
            if inc < 0:
                break
            res += inc
        return res
