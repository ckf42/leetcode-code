class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        tp1 = version1.split('.')
        tp2 = version2.split('.')
        for a, b in zip(tp1, tp2):
            ai, bi = int(a), int(b)
            if ai < bi:
                return -1
            elif ai > bi:
                return 1
        if len(tp1) > len(tp2):
            for x in tp1[len(tp2):]:
                if int(x) != 0:
                    return 1
        elif len(tp1) < len(tp2):
            for x in tp2[len(tp1):]:
                if int(x) != 0:
                    return -1
        return 0
