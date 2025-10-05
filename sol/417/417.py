class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        n = len(heights[0])
        memo = [[0] * n for _ in range(m)]
        buff = [(0, j, 1) for j in range(n)] \
            + [(i, 0, 1) for i in range(1, m)] \
            + [(m - 1, j, 2) for j in range(n)] \
            + [(i, n - 1, 2) for i in range(m - 1)]
        d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while len(buff) != 0:
            x, y, mask = buff.pop()
            if (memo[x][y] & mask) != 0:
                continue
            memo[x][y] |= mask
            for dx, dy in d:
                xx = x + dx
                yy = y + dy
                if 0 <= xx < m and 0 <= yy < n \
                        and heights[xx][yy] >= heights[x][y] \
                        and (memo[xx][yy] & mask) == 0:
                    buff.append((xx, yy, mask))
        return [(i, j) for i in range(m) for j in range(n) if memo[i][j] == 3]
