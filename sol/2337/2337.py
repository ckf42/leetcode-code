class Solution:
    def canChange(self, start: str, target: str) -> bool:
        unmatchedL = 0
        unmatchedR = 0
        for a, b in zip(start, target):
            if (a == 'L' and unmatchedR != 0) or (b == 'R' and unmatchedL != 0):
                return False
            unmatchedL += (b == 'L') - (a == 'L')
            unmatchedR += (a == 'R') - (b == 'R')
            if unmatchedL < 0 or unmatchedR < 0:
                return False
        return unmatchedL == 0 and unmatchedR == 0
