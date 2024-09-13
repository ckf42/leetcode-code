class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        res = [[-1] * n for _ in range(m)]
        i, j = 0, 0
        diffi, diffj = 0, 1
        while head is not None:
            res[i][j] = head.val
            head = head.next
            if not (0 <= i + diffi < m and 0 <= j + diffj < n and res[i + diffi][j + diffj] == -1):
                diffi, diffj = diffj, -diffi
            i += diffi
            j += diffj
        return res
