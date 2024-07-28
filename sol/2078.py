class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        res = 0
        for i in range(n - 1, 0, -1):
            if colors[i] != colors[0]:
                res = max(res, i)
                break
        for i in range(0, n - 1):
            if colors[i] != colors[n - 1]:
                res = max(res, n - 1 - i)
                break
        return res
