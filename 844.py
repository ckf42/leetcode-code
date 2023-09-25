class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        ptrs = len(s) - 1
        ptrt = len(t) - 1
        sBs = 0
        tBs = 0
        while True:
            while ptrs >= 0 and (s[ptrs] == '#' or sBs != 0):
                sBs += 1 if s[ptrs] == '#' else -1
                ptrs -= 1
            while ptrt >= 0 and (t[ptrt] == '#' or tBs != 0):
                tBs += 1 if t[ptrt] == '#' else -1
                ptrt -= 1
            if ptrs == -1 or ptrt == -1:
                return ptrs == ptrt
            if s[ptrs] != t[ptrt]:
                return False
            ptrs -= 1
            ptrt -= 1
