import bisect

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        idx = bisect.bisect_left(range(m * n), target, key=lambda i: matrix[i // n][i % n])
        return idx != m * n and matrix[idx // n][idx % n] == target
