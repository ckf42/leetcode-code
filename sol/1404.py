class Solution:
    def numSteps(self, s: str) -> int:
        count = 0
        j = len(s) - 1
        i = j
        while s[i] == '0':
            i -= 1
        count += j - i
        j = i
        while j > 0:
            i = j - 1
            while i >= 0 and s[i] == '1':
                i -= 1
            count += j - i + 1
            j = i
        return count
