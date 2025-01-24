class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        d = {
            mat[i][j]: (i, j)
            for i in range(m)
            for j in range(n)
        }
        rowCount = [0] * m
        colCount = [0] * n
        for t, x in enumerate(arr):
            i, j = d[x]
            rowCount[i] += 1
            colCount[j] += 1
            if rowCount[i] == n or colCount[j] == m:
                return t
        return -1

