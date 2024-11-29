#include <queue>

struct Solution {
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> reached(m, vector<bool>(n, false));
        deque<pair<int, pair<int, int>>> q;
        q.push_back({0, {0, 0}});
        while (!q.empty()){
            int cost = q.back().first;
            auto [i, j] = q.back().second;
            q.pop_back();
            if (i == m - 1 && j == n - 1){
                return cost;
            }
            if (reached[i][j]){
                continue;
            }
            reached[i][j] = true;
            int ii = i + 1, jj = j;
            if (ii < m && !reached[ii][jj]){
                if (grid[ii][jj]){
                    q.push_front({cost + 1, {ii, jj}});
                } else {
                    q.push_back({cost, {ii, jj}});
                }
            }
            ii = i, jj = j + 1;
            if (jj < n && !reached[ii][jj]){
                if (grid[ii][jj]){
                    q.push_front({cost + 1, {ii, jj}});
                } else {
                    q.push_back({cost, {ii, jj}});
                }
            }
            ii = i - 1, jj = j;
            if (ii >= 0 && !reached[ii][jj]){
                if (grid[ii][jj]){
                    q.push_front({cost + 1, {ii, jj}});
                } else {
                    q.push_back({cost, {ii, jj}});
                }
            }
            ii = i, jj = j - 1;
            if (jj >= 0 && !reached[ii][jj]){
                if (grid[ii][jj]){
                    q.push_front({cost + 1, {ii, jj}});
                } else {
                    q.push_back({cost, {ii, jj}});
                }
            }
        }
        return -1;
    }
};
