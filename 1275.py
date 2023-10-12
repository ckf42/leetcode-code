class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [[None for _ in range(3)] for __ in range(3)]
        isA = True
        for pos in moves:
            board[pos[0]][pos[1]] = isA
            isA = not isA
            for i in range(3):
                if board[i][0] == board[i][1] == board[i][2] is not None:
                    return "A" if board[i][0] else "B"
                if board[0][i] == board[1][i] == board[2][i] is not None:
                    return "A" if board[0][i] else "B"
            if board[1][1] is not None \
                and (board[0][0] == board[1][1] == board[2][2] \
                     or board[0][2] == board[1][1] == board[2][0]):
                return "A" if board[1][1] else "B"
        return "Pending" if len(moves) != 9 else "Draw"
