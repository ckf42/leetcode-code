struct Solution {
    bool isValidSudoku(vector<vector<char>>& board) {
        short r[9] = {0}, c[9] = {0}, b[9] = {0};
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                char x = board[i][j];
                if (x == '.'){
                    continue;
                }
                int m = 1 << (x - '1'), k = (i / 3) * 3 + (j / 3);
                if (((r[i] | c[j] | b[k]) & m) != 0){
                    return false;
                }
                r[i] |= m;
                c[j] |= m;
                b[k] |= m;
            }
        }
        return true;
    }
};
