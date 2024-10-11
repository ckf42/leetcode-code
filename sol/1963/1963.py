class Solution:
    def minSwaps(self, s: str) -> int:
        a = 0
        b = 0
        for c in s:
            if c == '[':
                b += 1
            elif b == 0:
                a += 1
            else:
                b -= 1
        return (a + 1) // 2
