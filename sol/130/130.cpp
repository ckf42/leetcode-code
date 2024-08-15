struct Solution {
    void protect(int i, int j, vector<vector<char>>& board){
        if (board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'o';
        if (i > 0){this->protect(i - 1, j, board);}
        if (i < board.size() - 1){this->protect(i + 1, j, board);}
        if (j > 0){this->protect(i, j - 1, board);}
        if (j < board.front().size() - 1){this->protect(i, j + 1, board);}
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        for (int i = 0; i < m; ++i){
            if (board[i][0] == 'O'){
                this->protect(i, 0, board);
            }
            if (board[i][n - 1] == 'O'){
                this->protect(i, n - 1, board);
            }
        }
        for (int j = 1; j < n - 1; ++j){
            if (board[0][j] == 'O'){
                this->protect(0, j, board);
            }
            if (board[m - 1][j] == 'O'){
                this->protect(m - 1, j, board);
            }
        }
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                switch (board[i][j]){
                    case 'O':
                        board[i][j] = 'X';
                        break;
                    case 'o':
                        board[i][j] = 'O';
                        break;
                }
            }
        }
    }
};
