#include <queue>

struct Solution {
    static constexpr int offsets[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), lvl = 0;
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> buff;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (isWater[i][j] == 1){
                    buff.push({i, j});
                }
            }
        }
        while (!buff.empty()){
            int s = buff.size();
            while (s-- > 0){
                auto [x, y] = buff.front();
                buff.pop();
                if (height[x][y] != -1){
                    continue;
                }
                height[x][y] = lvl;
                for (int d = 0; d < 4; ++d){
                    int xx = x + this->offsets[d][0],
                        yy = y + this->offsets[d][1];
                    if (0 <= xx && xx < m && 0 <= yy & yy < n && height[xx][yy] == -1){
                        buff.push({xx, yy});
                    }
                }
            }
            ++lvl;
        }
        return height;
    }
};
