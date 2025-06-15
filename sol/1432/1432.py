class Solution:
    def maxDiff(self, num: int) -> int:
        s = str(num)
        a = int(s.replace(next((d for d in s if d != '9'), '9'), '9'))
        b = 0
        l = len(s)
        if l == 1:
            b = 1
        elif s[0] != '1':
            b = int(s.replace(s[0], '1'))
        else:
            for i in range(1, l):
                if s[i] != '1' and s[i] != '0':
                    b = int(s.replace(s[i], '0'))
                    break
            else:
                b = num
        return a - b
