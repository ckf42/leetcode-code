class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        r = [0 for _ in range(m)]
        c = [0 for _ in range(n)]
        reg = list()
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    r[i] += 1
                    c[j] += 1
                    reg.append((i, j))
        return sum(1 for (i, j) in reg if r[i] == c[j] == 1)

