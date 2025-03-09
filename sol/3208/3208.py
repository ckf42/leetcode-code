class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        res = 0
        count = 1
        for i in range(1, n):
            if colors[i] != colors[i - 1]:
                count += 1
            else:
                count = 1
            if count >= k:
                res += 1
        for i in range(k - 1):
            if colors[i] != colors[i - 1]:
                count += 1
            else:
                count = 1
            if count >= k:
                res += 1
        return res
