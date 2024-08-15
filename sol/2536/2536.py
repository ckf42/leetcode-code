class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        d = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            d[r1][c1] += 1
            if r2 < n - 1:
                d[r2 + 1][c1] -= 1
            if c2 < n - 1:
                d[r1][c2 + 1] -= 1
            if r2 < n - 1 and c2 < n - 1:
                d[r2 + 1][c2 + 1] += 1
        for i in range(n):
            for j in range(1, n):
                d[i][j] += d[i][j - 1]
        for j in range(n):
            for i in range(1, n):
                d[i][j] += d[i - 1][j]
        return d
