class Solution:
    modulus = 12345
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        res = [[1] * m for _ in range(n)]
        p = 1
        for i in range(n):
            for j in range(m):
                res[i][j] = p
                grid[i][j] %= self.modulus
                p = (p * grid[i][j]) % self.modulus
        p = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                res[i][j] = (res[i][j] * p) % self.modulus
                p = (p * grid[i][j]) % self.modulus
        return res
