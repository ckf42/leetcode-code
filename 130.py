class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        def protect(i, j):
            nonlocal board
            if board[i][j] != 'O':
                return
            board[i][j] = '0'
            if i > 0:
                protect(i - 1, j)
            if i < m - 1:
                protect(i + 1, j)
            if j > 0:
                protect(i, j - 1)
            if j < n - 1:
                protect(i, j + 1)
        for i in range(m):
            if board[i][0] == 'O':
                protect(i, 0)
            if board[i][n - 1] == 'O':
                protect(i, n - 1)
        for j in range(1, n - 1):
            if board[0][j] == 'O':
                protect(0, j)
            if board[m - 1][j] == 'O':
                protect(m - 1, j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '0':
                    board[i][j] = 'O'
        
