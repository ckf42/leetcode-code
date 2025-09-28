from itertools import zip_longest

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        tp1 = [int(x) for x in version1.split('.')]
        tp2 = [int(x) for x in version2.split('.')]
        for a, b in zip_longest(tp1, tp2, fillvalue=0):
            if a < b:
                return -1
            if a > b:
                return 1
        return 0
