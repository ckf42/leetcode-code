class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        remainder = grid[0][0] % x
        valList = []
        for row in grid:
            for v in row:
                if v % x != remainder:
                    return -1
                valList.append(v)
        valList.sort()
        target = valList[len(valList) // 2]
        res = 0
        for v in valList:
            res += abs(v - target) // x
        return res

