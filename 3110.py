class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        prev = ord(s[0])
        for c in s:
            score += abs(ord(c) - prev)
            prev = ord(c)
        return score
