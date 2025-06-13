class Solution:
    def maxDifference(self, s: str) -> int:
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        a1 = 0
        a2 = len(s)
        for f in freq:
            if f & 1:
                a1 = max(a1, f)
            elif f != 0:
                a2 = min(a2, f)
        return a1 - a2
