class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        total = 0
        prefix = [(-1, 0)]
        for p, a in fruits:
            total += a
            prefix.append((p, total))
        n = len(prefix)
        res = 0
        l = 0
        while l < n and prefix[l][0] < startPos - k:
            l += 1
        r = l
        while l < n and prefix[l][0] <= startPos:
            while r < n - 1 and prefix[r + 1][0] * 2 <= k + startPos + prefix[l][0]:
                r += 1
            res = max(res, prefix[r][1] - prefix[l - 1][1])
            l += 1
        r = l
        l = 1
        while r < n and prefix[r][0] <= startPos + k:
            while l < n and startPos + prefix[r][0] - k > prefix[l][0] * 2:
                l += 1
            res = max(res, prefix[r][1] - prefix[l - 1][1])
            r += 1
        return res

