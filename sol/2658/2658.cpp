struct Solution {
    static constexpr int DIRS[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 0){
                    continue;
                }
                int total = 0;
                vector<pair<int, int>> buff;
                buff.push_back({i, j});
                while (!buff.empty()){
                    auto [x, y] = buff.back();
                    buff.pop_back();
                    if (grid[x][y] == 0){
                        continue;
                    }
                    total += grid[x][y];
                    grid[x][y] = 0;
                    for (int d = 0; d < 4; ++d){
                        int xx = x + this->DIRS[d][0],
                            yy = y + this->DIRS[d][1];
                        if (0 <= xx && xx < m && 0 <= yy && yy < n && grid[xx][yy] != 0){
                            buff.push_back({xx, yy});
                        }
                    }
                }
                res = max(res, total);
            }
        }
        return res;
    }
};
