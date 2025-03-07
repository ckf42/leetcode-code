class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        count = [0] * (n * n)
        for row in grid:
            for x in row:
                count[x - 1] += 1
        res = [0, 0]
        for i, v in enumerate(count, 1):
            if v == 0:
                res[1] = i
            elif v == 2:
                res[0] = i
        return res
