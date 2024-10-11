class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        a = 0
        b = 0
        for c in s:
            if c == '(':
                b += 1
            elif b != 0:
                b -= 1
            else:
                a += 1
        return a + b
