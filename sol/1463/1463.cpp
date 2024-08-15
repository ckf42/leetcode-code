struct Solution {
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), count;
        int memo[70][70][70];
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                for (int k = 0; k < c; ++k){
                    memo[i][j][k] = -1;
                }
            }
        }
        memo[0][0][c - 1] = grid[0][0] + grid[0][c - 1];
        for (int i = 1; i < r; ++i){
            for (int newj = 0; newj < c - 1; ++newj){
                for (int newk = newj + 1; newk < c; ++newk){
                    count = grid[i][newj] + grid[i][newk];
                    for (int oldj = newj - 1; oldj <= newj + 1; ++oldj){
                        if (oldj < 0 || oldj >= c){
                            continue;
                        }
                        for (int oldk = newk - 1; oldk <= newk + 1; ++oldk){
                            if (oldk < 0 || oldk >= c || memo[i - 1][oldj][oldk] == -1){
                                continue;
                            }
                            memo[i][newj][newk] = max(
                                memo[i][newj][newk],
                                memo[i - 1][oldj][oldk] + count
                            );
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j < c - 1; ++j){
            for (int k = j + 1; k < c; ++k){
                res = max(res, memo[r - 1][j][k]);
            }
        }
        return res;
    }
};
