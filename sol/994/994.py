from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        count = 0
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    count += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
        if count == 0:
            return 0
        curr = 0
        while (s := len(q)) != 0:
            for _ in range(s):
                i, j = q.popleft()
                if i > 0 and grid[i - 1][j] == 1:
                    grid[i - 1][j] = 2
                    count -= 1
                    q.append((i - 1, j))
                if i < m - 1 and grid[i + 1][j] == 1:
                    grid[i + 1][j] = 2
                    count -= 1
                    q.append((i + 1, j))
                if j > 0 and grid[i][j - 1] == 1:
                    grid[i][j - 1] = 2
                    count -= 1
                    q.append((i, j - 1))
                if j < n - 1 and grid[i][j + 1] == 1:
                    grid[i][j + 1] = 2
                    count -= 1
                    q.append((i, j + 1))
            curr += 1
        if count == 0:
            return curr - 1
        else:
            return -1
        
