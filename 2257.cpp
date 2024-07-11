struct Solution {
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 0));
        for (auto &e : walls){
            grid[e[0]][e[1]] = 1;
        }
        for (auto &e : guards){
            int i = e[0], j = e[1];
            grid[i][j] = 6;
            for (int x = i - 1; x >= 0; --x){
                if (grid[x][j] & 3){ break; }
                grid[x][j] |= 2;
            }
            for (int x = i + 1; x < m; ++x){
                if (grid[x][j] & 3){ break; }
                grid[x][j] |= 2;
            }
            for (int x = j - 1; x >= 0; --x){
                if (grid[i][x] & 5){ break; }
                grid[i][x] |= 4;
            }
            for (int x = j + 1; x < n; ++x){
                if (grid[i][x] & 5){ break; }
                grid[i][x] |= 4;
            }
        }
        int res = 0;
        for (auto &r : grid){
            for (auto &x : r){
                res += (x == 0);
            }
        }
        return res;
    }
};
