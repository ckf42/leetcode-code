struct Solution {
    bool backtrack(
            int i, int j, int ptr, 
            const vector<vector<char>> &board, 
            const string &word, vector<vector<bool>> &used){
        if (i < 0 || i >= board.size() || j < 0 || j >= board.front().size() || board[i][j] != word[ptr] || used[i][j]){
            return false;
        }
        if (ptr == word.size() - 1){
            return true;
        }
        used[i][j] = true;
        ++ptr;
        bool res = backtrack(i - 1, j, ptr, board, word, used)
                || backtrack(i + 1, j, ptr, board, word, used)
                || backtrack(i, j - 1, ptr, board, word, used)
                || backtrack(i, j + 1, ptr, board, word, used);
        used[i][j] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string &word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board.front().size(); ++j){
                if (backtrack(i, j, 0, board, word, used)){
                    return true;
                }
            }
        }
        return false;
    }
};
