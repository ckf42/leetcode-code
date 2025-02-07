class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        h = dict()
        n = len(nums)
        for i in range(n - 1):
            for j in range(i + 1, n):
                p = nums[i] * nums[j]
                h[p] = h.get(p, 0) + 1
        return sum(
            x * (x - 1) * 4
            for x in h.values()
        )
