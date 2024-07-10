class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)
        def count(x: int) -> int:
            c, d = 0, 0
            for i in range(n):
                t, b = tops[i], bottoms[i]
                if t != x and b != x:
                    return -1
                if t != x and b == x:
                    c += 1
                if b != x and t == x:
                    d += 1
            return min(c, d)
        res = count(tops[0])
        if tops[0] != bottoms[0]:
            val = count(bottoms[0])
            if res == -1 or (res > val != -1):
                res = val
        return res

