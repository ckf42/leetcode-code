struct Solution {
    static constexpr int DX[4] = {0, 0, 1, -1},
                         DY[4] = {1, -1, 0, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        vector<int> buff;
        for (int j = 0; j < n; ++j){
            buff.push_back((0 * 200 + j) * 2 + 0);
            buff.push_back(((m - 1) * 200 + j) * 2 + 1);
        }
        for (int i = 0; i < m; ++i){
            buff.push_back((i * 200 + 0) * 2 + 0);
            buff.push_back((i * 200 + n - 1) * 2 + 1);
        }
        while (!buff.empty()){
            int v = buff.back();
            buff.pop_back();
            int mask = (v & 1) + 1;
            v >>= 1;
            int y = v % 200, x = v / 200;
            if (memo[x][y] & mask){
                continue;
            }
            memo[x][y] |= mask;
            for (int d = 0; d < 4; ++d){
                int xx = x + DX[d], yy = y + DY[d];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && heights[xx][yy] >= heights[x][y] && (memo[xx][yy] & mask) == 0){
                    buff.push_back((xx * 200 + yy) * 2 + mask - 1);
                }
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (memo[i][j] == 3){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
