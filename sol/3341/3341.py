import heapq as hq

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])
        h = [(0, 0, 0)]
        visited = [[False] * m for _ in range(n)]
        while len(h) != 0:
            t, x, y = hq.heappop(h)
            if (x, y) == (n - 1, m - 1):
                return t
            if visited[x][y]:
                continue
            visited[x][y] = True
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                xx = x + dx
                yy = y + dy
                if 0 <= xx < n and 0 <= yy < m and not visited[xx][yy]:
                    hq.heappush(h, (max(t, moveTime[xx][yy]) + 1, xx, yy))
        return -1
