class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r = [0] * 9
        c = [0] * 9
        b = [0] * 9
        for i in range(9):
            for j in range(9):
                x = board[i][j]
                if x == '.':
                    continue
                m = 1 << (ord(x) - ord('0'))
                if ((r[i] | c[j] | b[(i // 3) * 3 + j // 3]) & m) != 0:
                    return False
                r[i] |= m
                c[j] |= m
                b[(i // 3) * 3 + j // 3] |= m
        return True
