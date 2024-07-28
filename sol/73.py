class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        markerRow, markerCol = -1, -1
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    markerRow, markerCol = i, j
                    break
            if markerRow != -1:
                break
        if markerRow == -1:
            return
        for i in range(m):
            if i == markerRow:
                continue
            matrix[i][markerCol] = 0 if matrix[i][markerCol] != 0 else 1
        for j in range(n):
            if j == markerCol:
                continue
            matrix[markerRow][j] = 0 if matrix[markerRow][j] != 0 else 1
        for i in range(markerRow + 1, m):
            for j in range(n):
                if j == markerCol:
                    continue
                if matrix[i][j] == 0:
                    matrix[markerRow][j] = 1
                    matrix[i][markerCol] = 1
        for i in range(m):
            if matrix[i][markerCol] == 1:
                for j in range(n):
                    matrix[i][j] = 0
        for j in range(n):
            if matrix[markerRow][j] == 1:
                for i in range(m):
                    matrix[i][j] = 0


