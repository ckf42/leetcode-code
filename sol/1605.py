import heapq as hq

class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        r = len(rowSum)
        c = len(colSum)
        res = [[-1] * c for _ in range(r)]
        rowDone = [False] * r
        colDone = [False] * c
        h = [
            (x, i, False) for i, x in enumerate(rowSum)
        ] + [
            (x, i, True) for i, x in enumerate(colSum)
        ]
        hq.heapify(h)
        while len(h) != 0:
            x, i, isCol = hq.heappop(h)
            if isCol:
                if colDone[i]:
                    continue
                for j in range(r):
                    if res[j][i] != -1:
                        continue
                    if not colDone[i]:
                        colDone[i] = True
                        res[j][i] = x
                        rowSum[j] -= x
                        hq.heappush(h, (rowSum[j], j, False))
                    else:
                        res[j][i] = 0
            else:
                if rowDone[i]:
                    continue
                for j in range(c):
                    if res[i][j] != -1:
                        continue
                    if not rowDone[i]:
                        rowDone[i] = True
                        res[i][j] = x
                        colSum[j] -= x
                        hq.heappush(h, (colSum[j], j, True))
                    else:
                        res[i][j] = 0
        return res
