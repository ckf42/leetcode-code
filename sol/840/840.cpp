struct Solution {
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        for (int i = 0; i < row - 2; ++i){
            for (int j = 0; j < col - 2; ++j){
                if (grid[i + 1][j + 1] != 5){
                    continue;
                }
                int m = 0, rowsum[3] = {0}, colsum[3] = {0};
                for (int di = 0; di < 3; ++di){
                    for (int dj = 0; dj < 3; ++dj){
                        m |= 1 << grid[i + di][j + dj];
                        rowsum[di] += grid[i + di][j + dj];
                        colsum[dj] += grid[i + di][j + dj];
                    }
                }
                if (m == 1022
                        && rowsum[0] == 15 && rowsum[1] == 15 && rowsum[2] == 15
                        && colsum[0] == 15 && colsum[1] == 15 && colsum[2] == 15
                        && grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15
                        && grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] == 15){
                    ++res;
                }
            }
        }
        return res;
    }
};
