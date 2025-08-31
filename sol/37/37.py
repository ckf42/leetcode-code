class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        r = [0] * 9
        c = [0] * 9
        b = [0] * 9
        spaces = []
        mdict = {str(i): 1 << i for i in range(9 + 1)}
        mlist = tuple(1 << i for i in range(9 + 1))
        chars = tuple(str(i) for i in range(9 + 1))
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    spaces.append((i, j))
                    continue
                m = mdict[board[i][j]]
                r[i] |= m
                c[j] |= m
                b[(i // 3) * 3 + (j // 3)] |= m
        l = len(spaces)
        def backtrack(ptr):
            nonlocal r
            nonlocal c
            nonlocal b
            nonlocal board
            if ptr == l:
                return True
            i, j = spaces[ptr]
            d = (i // 3) * 3 + (j // 3)
            for cand in range(1, 9 + 1):
                m = mlist[cand]
                if ((r[i] | c[j] | b[d]) & m) != 0:
                    continue
                r[i] |= m
                c[j] |= m
                b[d] |= m
                board[i][j] = chars[cand]
                if backtrack(ptr + 1):
                    return True
                r[i] ^= m
                c[j] ^= m
                b[d] ^= m
                board[i][j] = '.'
            return False
        backtrack(0)

            
