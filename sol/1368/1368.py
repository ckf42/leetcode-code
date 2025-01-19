class Solution:
    OFFSETS = (
        (0, 0),
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0)
    )
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        target = (m - 1, n - 1)
        visited = set()
        toExtend = [(0, 0)]
        cost = 0
        while len(toExtend) != 0:
            newNodes = []
            while len(toExtend) != 0:
                x, y = toExtend.pop()
                while 0 <= x < m and 0 <= y < n and (x, y) not in visited:
                    visited.add((x, y))
                    newNodes.append((x, y))
                    dx, dy = self.OFFSETS[grid[x][y]]
                    x += dx
                    y += dy
                if target in visited:
                    return cost
            cost += 1
            for x, y in newNodes:
                for newDir in range(1, 5):
                    if newDir == grid[x][y]:
                        continue
                    dx, dy = self.OFFSETS[newDir]
                    xx = x + dx
                    yy = y + dy
                    if 0 <= xx < m and 0 <= yy < n and not (xx, yy) in visited:
                        toExtend.append((xx, yy))
        return cost
