import heapq as hq

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        q = len(queries)
        sortedIdx = sorted(range(q), key=lambda i: queries[i])
        res = [0] * q
        count = 0
        threshold = 10 ** 7
        h = [(grid[0][0], 0, 0)]
        grid[0][0] = threshold
        for idx in sortedIdx:
            query = queries[idx]
            while len(h) != 0 and h[0][0] < query:
                _, x, y = hq.heappop(h)
                count += 1
                if x > 0 and grid[x - 1][y] < threshold:
                    hq.heappush(h, (grid[x - 1][y], x - 1, y))
                    grid[x - 1][y] = threshold
                if x < m - 1 and grid[x + 1][y] < threshold:
                    hq.heappush(h, (grid[x + 1][y], x + 1, y))
                    grid[x + 1][y] = threshold
                if y > 0 and grid[x][y - 1] < threshold:
                    hq.heappush(h, (grid[x][y - 1], x, y - 1))
                    grid[x][y - 1] = threshold
                if y < n - 1 and grid[x][y + 1] < threshold:
                    hq.heappush(h, (grid[x][y + 1], x, y + 1))
                    grid[x][y + 1] = threshold
            res[idx] = count
        return res
