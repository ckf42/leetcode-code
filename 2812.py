import heapq as hq

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return 0
        dist = [[-1] * n for _ in range(n)]
        toUpdate = set(((i, j) for i in range(n) for j in range(n) if grid[i][j] == 1))
        d = 0
        while len(toUpdate) != 0:
            nextToUpdate = set()
            for i, j in toUpdate:
                if dist[i][j] != -1:
                    continue
                dist[i][j] = d
                if i > 0:
                    nextToUpdate.add((i - 1, j))
                if i < n - 1:
                    nextToUpdate.add((i + 1, j))
                if j > 0:
                    nextToUpdate.add((i, j - 1))
                if j < n - 1:
                    nextToUpdate.add((i, j + 1))
            toUpdate = nextToUpdate
            d += 1
        h = [(-dist[0][0], 0, 0)]
        visited = set()
        while len(h) != 0:
            factor, i, j = hq.heappop(h)
            if i == n - 1 == j:
                return -factor
            if (i, j) in visited:
                continue
            visited.add((i, j))
            if i > 0:
                hq.heappush(h, (max(factor, -dist[i - 1][j]), i - 1, j))
            if i < n - 1:
                hq.heappush(h, (max(factor, -dist[i + 1][j]), i + 1, j))
            if j > 0:
                hq.heappush(h, (max(factor, -dist[i][j - 1]), i, j - 1))
            if j < n - 1:
                hq.heappush(h, (max(factor, -dist[i][j + 1]), i, j + 1))
        return -1
