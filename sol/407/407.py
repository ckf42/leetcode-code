import heapq as hq

class Solution:
    OFFSETS = (
        (1, 0),
        (-1, 0),
        (0, 1),
        (0, -1),
    )
    MAXHEIGHT = 2 * 10 ** 4 + 1
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m = len(heightMap)
        n = len(heightMap[0])
        if m <= 2 or n <= 2:
            return 0
        total = 0
        isBdy = [[False] * n for i in range(m)]
        h = []
        for i in range(m):
            for j in (0, n - 1):
                h.append((heightMap[i][j], i, j))
        for i in (0, m - 1):
            for j in range(1, n - 1):
                h.append((heightMap[i][j], i, j))
        hq.heapify(h)
        while len(h) != 0:
            height, x, y = hq.heappop(h)
            if isBdy[x][y]:
                continue
            maxHeight = self.MAXHEIGHT
            for dx, dy in self.OFFSETS:
                xx = x + dx
                yy = y + dy
                if xx < 0 or xx >= m or yy < 0 or yy >= n:
                    maxHeight = 0
                elif isBdy[xx][yy]:
                    maxHeight = min(maxHeight, heightMap[xx][yy])
                else:
                    hq.heappush(h, (heightMap[xx][yy], xx, yy))
            if maxHeight > height:
                total += maxHeight - height
                heightMap[x][y] = maxHeight
            isBdy[x][y] = True
        return total
