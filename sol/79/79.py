class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        w = len(word)
        used = [[False] * n for _ in range(m)]

        def backtrack(i, j, ptr):
            if ptr == w - 1:
                return True
            used[i][j] = True
            for (di, dj) in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ii = i + di
                jj = j + dj
                if 0 <= ii < m and 0 <= jj < n and board[ii][jj] == word[ptr + 1] and not used[ii][jj]:
                    if backtrack(ii, jj, ptr + 1):
                        return True
            used[i][j] = False
            return False

        for state in ((i, j) for i in range(m) for j in range(n) if board[i][j] == word[0]):
            if backtrack(*state, 0):
                return True
        return False

