class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        res = list()
        pos = [0, 0]
        newPos = [0, 0]
        dirDict = ((1, 0), (0, -1), (-1, 0), (0, 1))
        d = 3
        while True:
            pos[0] = newPos[0]
            pos[1] = newPos[1]
            res.append(matrix[pos[0]][pos[1]])
            matrix[pos[0]][pos[1]] = -101
            newPos[0] = pos[0] + dirDict[d][0]
            newPos[1] = pos[1] + dirDict[d][1]
            if not (0 <= newPos[0] < m and 0 <= newPos[1] < n and matrix[newPos[0]][newPos[1]] != -101):
                d = (d + 1) & 3
            newPos[0] = pos[0] + dirDict[d][0]
            newPos[1] = pos[1] + dirDict[d][1]
            if not (0 <= newPos[0] < m and 0 <= newPos[1] < n and matrix[newPos[0]][newPos[1]] != -101):
                break
        return res
