class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        res = []
        m, n = len(land), len(land[0])
        for i in range(m):
            for j in range(n):
                if land[i][j] != 1:
                    continue
                r = i
                while r < m and land[r][j] == 1:
                    r += 1
                b = j
                while b < n and land[i][b] == 1:
                    b += 1
                for ii in range(i, r):
                    for jj in range(j, b):
                        land[ii][jj] = 2
                res.append([i, j, r - 1, b - 1])
        return res
