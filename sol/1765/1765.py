from collections import deque

class Solution:
    OFFSETS = (
        (1, 0),
        (0, 1),
        (-1, 0),
        (0, -1)
    )
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m = len(isWater)
        n = len(isWater[0])
        height = [[-1] * n for _ in range(m)]
        lvl = 0
        buff = deque([(i, j) for i in range(m) for j in range(n) if isWater[i][j] == 1])
        while (s := len(buff)) != 0:
            for _ in range(s):
                x, y = buff.popleft()
                if height[x][y] != -1:
                    continue
                height[x][y] = lvl
                for dx, dy in self.OFFSETS:
                    xx = x + dx
                    yy = y + dy
                    if 0 <= xx < m and 0 <= yy < n and height[xx][yy] == -1:
                        buff.append((xx, yy))
            lvl += 1
        return height
