class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        p = list(p)
        ptr = 0
        while ptr < len(p):
            if p[ptr] == '*':
                ptrr = ptr + 1
                while ptrr < len(p) and p[ptrr] == '*':
                    ptrr += 1
                p[ptr + 1:ptrr] = list()
            ptr += 1
        hasMatch = [False] * (len(s) + 1)
        hasMatch[len(s)] = True
        for pi in range(len(p) - 1, -1, -1):
            if p[pi] == '*':
                firstIdx = next((si for si in range(len(s), -1, -1) if hasMatch[si]), None)
                if firstIdx is not None:
                    for si in range(len(s)):
                        hasMatch[si] = si <= firstIdx
            else:
                for si in range(len(s)):
                    hasMatch[si] = (p[pi] == '?' or s[si] == p[pi]) and hasMatch[si + 1]
            hasMatch[len(s)] &= p[pi] == '*'
        return hasMatch[0]
