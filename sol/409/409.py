from collections import Counter

class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        hasOdd = False
        total = 0
        for v in c.values():
            if v & 1:
                hasOdd = True
                total += v - 1
            else:
                total += v
        return total + hasOdd
