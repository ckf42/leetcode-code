class Solution:
    def makeFancyString(self, s: str) -> str:
        letter = None
        streak = 0
        res = ''
        for c in s:
            if c == letter and streak == 2:
                continue
            elif c == letter:
                streak += 1
            else:
                letter = c
                streak = 1
            res += c
        return res
