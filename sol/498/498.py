class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        res = []
        for l in range(m + n):
            if l & 1:
                res.extend((mat[i][l - i] for i in range(max(0, l - n + 1), min(m, l + 1))))
            else:
                res.extend((mat[l - j][j] for j in range(max(0, l - m + 1), min(n, l + 1))))
        return res
