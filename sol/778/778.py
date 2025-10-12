import heapq as hq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        h = [(grid[0][0], 0, 0)]
        visited = set()
        d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while True:
            t, x, y = hq.heappop(h)
            if (x, y) == (n - 1, n - 1):
                return t
            if (x, y) in visited:
                continue
            visited.add((x, y))
            for dx, dy in d:
                xx, yy = x + dx, y + dy
                if 0 <= xx < n and 0 <= yy < n and (xx, yy) not in visited:
                    hq.heappush(h, (max(t, grid[xx][yy]), xx, yy))

