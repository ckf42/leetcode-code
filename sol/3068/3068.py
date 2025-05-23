class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        xorinc = [(x ^ k) - x for x in nums]
        xorinc.sort(reverse=True)
        return sum(nums) + sum(inc for i in range(n // 2) if (inc := xorinc[i * 2] + xorinc[i * 2 + 1]) >= 0)
