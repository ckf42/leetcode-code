class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) & 1:
            return False
        upper = 0
        lower = 0
        for c, isLocked in zip(s, locked):
            if isLocked == '0':
                upper += 1
                lower -= 1
            elif c == '(':
                upper += 1
                lower += 1
            else:
                upper -= 1
                lower -= 1
            if upper < 0:
                return False
            if lower < 0:
                lower %= 2
                if upper < lower:
                    return False
        return lower == 0
