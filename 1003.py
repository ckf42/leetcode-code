class Solution:
    def isValid(self, s: str) -> bool:
        while len(s) != 0:
            ss = s.replace('abc', '')
            if len(ss) == len(s):
                return False
            s = ss
        return True

