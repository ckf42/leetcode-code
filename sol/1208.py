class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        diffs = tuple(abs(ord(a) - ord(b)) for a, b in zip(s, t))
        currCost = 0
        j = 0
        maxLen = 0
        for i in range(n):
            while j < n and currCost + diffs[j] <= maxCost:
                currCost += diffs[j]
                j += 1
            maxLen = max(maxLen, j - i)
            currCost -= diffs[i]
        return maxLen
