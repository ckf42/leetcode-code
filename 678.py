class Solution:
    def checkValidString(self, s: str) -> bool:
        depMin, depMax = 0, 0
        for c in s:
            if c == '(':
                depMin += 1
                depMax += 1
            elif c == ')':
                depMin -= 1
                depMax -= 1
            elif c == '*':
                depMin -= 1
                depMax += 1
            if depMax < 0:
                return False
            depMin = max(0, depMin)
        return depMin == 0
