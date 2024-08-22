from functools import cache
from itertools import groupby

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        gp = tuple((k, len(tuple(v))) for k, v in groupby(boxes))
        ngp = len(gp)
        @cache
        def dp(i, j, k):
            if i > j:
                return 0
            p = (k + gp[i][1]) ** 2 + dp(i + 1, j, 0)
            for m in range(i + 1, j + 1):
                if gp[m][0] == gp[i][0]:
                    p = max(
                        p,
                        dp(i + 1, m - 1, 0) + dp(m, j, k + gp[i][1])
                    )
            return p
        return dp(0, ngp - 1, 0)
