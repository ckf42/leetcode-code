class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r = [0] * 9
        c = [0] * 9
        b = [0] * 9
        md = {str(i): 1 << i for i in range(10)}
        q = tuple(i // 3 for i in range(9))
        for i in range(9):
            for j in range(9):
                x = board[i][j]
                if x == '.':
                    continue
                m = md[x]
                d = q[i] * 3 + q[j]
                if ((r[i] | c[j] | b[d]) & m) != 0:
                    return False
                r[i] |= m
                c[j] |= m
                b[d] |= m
        return True
