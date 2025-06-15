class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        firstNotNine = -1
        for i, c in enumerate(s):
            if c != '9':
                firstNotNine = i
                break
        else:
            return num
        return int(s.replace(s[firstNotNine], '9')) - int(s.replace(s[0], '0'))
