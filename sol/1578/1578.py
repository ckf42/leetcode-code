class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        res = 0
        prev = ' '
        maxt = 0
        for c, t in zip(colors, neededTime):
            if c == prev:
                if t > maxt:
                    t, maxt = maxt, t
                res += t
            else:
                prev = c
                maxt = t
        return res
