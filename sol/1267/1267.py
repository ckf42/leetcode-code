class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        count = 0
        rowCount = [list() for _ in range(m)]
        colCount = [list() for _ in range(n)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                count += 1
                rowCount[i].append(j)
                colCount[j].append(i)
        for i in range(m):
            if len(rowCount[i]) == 1:
                count -= len(colCount[rowCount[i][0]]) == 1
        return count
