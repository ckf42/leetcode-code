struct Solution {
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> vSeg(n, vector<int>(m, 0)), hSeg(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i){
            hSeg[i][0] = grid[i][0];
            for (int j = 1; j < m; ++j){
                if (grid[i][j] == 1){
                    hSeg[i][j] = hSeg[i][j - 1] + 1;
                }
            }
        }
        for (int j = 0; j < m; ++j){
            vSeg[0][j] = grid[0][j];
            for (int i = 1; i < n; ++i){
                if (grid[i][j] == 1){
                    vSeg[i][j] = vSeg[i - 1][j] + 1;
                }
            }
        }
        int res = 0;
        for (int d = n + m - 2; d >= 0; --d){
            if (d / 2 + 1 < res){
                break;
            }
            for (int i = min(n - 1, d); i >= max(0, d - m + 1); --i){
                int j = d - i;
                if (min(i, j) + 1 < res){
                    continue;
                }
                for (int l = min(hSeg[i][j], vSeg[i][j]); l >= 1; --l){
                    if (min(hSeg[i - l + 1][j], vSeg[i][j - l + 1]) >= l){
                        res = max(res, l);
                        break;
                    }
                }
            }
        }
        return res * res;
    }
};
