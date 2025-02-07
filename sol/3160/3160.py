class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ballColor = dict()
        colorCount = dict()
        n = len(queries)
        res = [0] * n
        for i, (x, newColor) in enumerate(queries):
            if x in ballColor:
                oldColor = ballColor[x]
                colorCount[oldColor] -= 1
                if colorCount[oldColor] == 0:
                    del colorCount[oldColor]
            colorCount[newColor] = colorCount.get(newColor, 0) + 1
            ballColor[x] = newColor
            res[i] = len(colorCount)
        return res
