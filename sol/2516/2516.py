class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        totals = [0] * 3
        for c in s:
            totals[ord(c) - ord('a')] += 1
        if any(x < k for x in totals):
            return -1
        res = -1
        l = 0
        counts = [0] * 3
        for r in range(n):
            idx = ord(s[r]) - ord('a')
            counts[idx] += 1
            while l <= r and counts[idx] > totals[idx] - k:
                counts[ord(s[l]) - ord('a')] -= 1
                l += 1
            res = max(res, r - l + 1)
        return n - res

