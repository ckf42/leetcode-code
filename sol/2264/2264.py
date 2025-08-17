class Solution:
    def largestGoodInteger(self, num: str) -> str:
        prev = ''
        count = 0
        maxChar = ''
        for c in num:
            if c != prev:
                if count >= 3:
                    maxChar = max(maxChar, prev)
                prev = c
                count = 0
            count += 1
        if count >= 3:
            maxChar = max(maxChar, prev)
        return maxChar * 3
