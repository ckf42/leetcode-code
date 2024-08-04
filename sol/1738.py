import heapq as hq

class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        h = []
        n = len(matrix)
        m = len(matrix[0])
        hq.heappush(h, matrix[0][0])
        for j in range(1, m):
            matrix[0][j] ^= matrix[0][j - 1]
            (hq.heappush if len(h) < k else hq.heappushpop)(h, matrix[0][j])
        for i in range(1, n):
            matrix[i][0] ^= matrix[i - 1][0]
            (hq.heappush if len(h) < k else hq.heappushpop)(h, matrix[i][0])
            for j in range(1, m):
                matrix[i][j] ^= matrix[i][j - 1] ^ matrix[i - 1][j] ^ matrix[i - 1][j - 1]
                (hq.heappush if len(h) < k else hq.heappushpop)(h, matrix[i][j])
        return h[0]
