from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        N = n * n
        vallocx = [0] * (N + 1)
        vallocy = [0] * (N + 1)
        for x in range(n):
            for y in range(n):
                v = x * n + y + 1
                vallocx[v] = n - 1 - x
                vallocy[v] = y if x % 2 == 0 else n - 1 - y
        visited = [False] * (N + 1)
        q = deque([1])
        d = 0
        while (s := len(q)) != 0:
            for _ in range(s):
                val = q.popleft()
                if val == N:
                    return d
                if visited[val]:
                    continue
                visited[val] = True
                for newv in range(val + 1, min(val + 6, N) + 1):
                    newx, newy = vallocx[newv], vallocy[newv]
                    if board[newx][newy] == -1:
                        q.append(newv)
                    else:
                        q.append(board[newx][newy])
            d += 1
        return -1
