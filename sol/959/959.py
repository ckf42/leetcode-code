class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        visited = [False] * (n * n * 4)
        res = 0
        def mark(i, j, k, coor):
            nonlocal visited
            if visited[coor]:
                return
            visited[coor] = True
            if grid[i][j] != '/':
                mark(i, j, 3 - k, coor - k * 2 + 3)
            if grid[i][j] != '\\':
                mark(i, j, k ^ 1, coor ^ 1)
            if k == 0 and j != n - 1:
                mark(i, j + 1, 2, coor + 6)
            elif k == 1 and i != n - 1:
                mark(i + 1, j, 3, coor + n * 4 + 2)
            elif k == 2 and j != 0:
                mark(i, j - 1, 0, coor - 6)
            elif k == 3 and i != 0:
                mark(i - 1, j, 1, coor - n * 4 - 2)
        coor = 0
        for i in range(n):
            for j in range(n):
                for k in range(4):
                    if not visited[coor]:
                        res += 1
                        mark(i, j, k, coor)
                    coor += 1
        return res
