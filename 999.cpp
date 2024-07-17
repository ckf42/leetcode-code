struct Solution {
    int numRookCaptures(vector<vector<char>>& board) {
        constexpr int n = 8;
        int ri = -1, rj = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'R'){
                    ri = i;
                    rj = j;
                    break;
                }
            }
            if (ri != -1){
                break;
            }
        }
        int count = 0;
        for (int ii = ri - 1; ii >= 0; --ii){
            count += board[ii][rj] == 'p';
            if (board[ii][rj] != '.'){break;}
        }
        for (int ii = ri + 1; ii < n; ++ii){
            count += board[ii][rj] == 'p';
            if (board[ii][rj] != '.'){break;}
        }
        for (int jj = rj - 1; jj >= 0; --jj){
            count += board[ri][jj] == 'p';
            if (board[ri][jj] != '.'){break;}
        }
        for (int jj = rj + 1; jj < n; ++jj){
            count += board[ri][jj] == 'p';
            if (board[ri][jj] != '.'){break;}
        }
        return count;
    }
};
