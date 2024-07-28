class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        n = 8
        ri, rj = -1, -1
        for i in range(n):
            for j in range(n):
                if board[i][j] == 'R':
                    ri, rj = i, j
                    break
            if ri != -1:
                break
        count = 0
        for ii in range(i - 1, -1, -1):
            count += board[ii][j] == 'p'
            if board[ii][j] != '.':
                break
        for ii in range(i + 1, n):
            count += board[ii][j] == 'p'
            if board[ii][j] != '.':
                break
        for jj in range(j - 1, -1, -1):
            count += board[i][jj] == 'p'
            if board[i][jj] != '.':
                break
        for jj in range(j + 1, n):
            count += board[i][jj] == 'p'
            if board[i][jj] != '.':
                break
        return count
