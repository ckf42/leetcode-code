#include <queue>

struct Solution {
    using state = pair<int, pair<int, int>>;
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }
        priority_queue<state, vector<state>, decltype([](const state &a, const state &b){return a.first > b.first;})> q;
        q.push({0, {0, 0}});
        vector<vector<bool>> pushed(m, vector<bool>(n, false));
        pushed[0][0] = true;
        while (!q.empty()){
            auto [t, coor] = q.top();
            auto [i, j] = coor;
            q.pop();
            if (i == m - 1 && j == n - 1){
                return t;
            }
            ++t;
            int ii = i + 1, jj = j, cost = t;
            if (ii < m && !pushed[ii][jj]){
                if (grid[ii][jj] > t){
                    cost = grid[ii][jj] + ((grid[ii][jj] ^ t) & 1);
                }
                pushed[ii][jj] = true;
                q.push({cost, {ii, jj}});
            }
            ii = i, jj = j + 1, cost = t;
            if (jj < n && !pushed[ii][jj]){
                if (grid[ii][jj] > t){
                    cost = grid[ii][jj] + ((grid[ii][jj] ^ t) & 1);
                }
                pushed[ii][jj] = true;
                q.push({cost, {ii, jj}});
            }
            ii = i - 1, jj = j, cost = t;
            if (ii >= 0 && !pushed[ii][jj]){
                if (grid[ii][jj] > t){
                    cost = grid[ii][jj] + ((grid[ii][jj] ^ t) & 1);
                }
                pushed[ii][jj] = true;
                q.push({cost, {ii, jj}});
            }
            ii = i, jj = j - 1, cost = t;
            if (jj >= 0 && !pushed[ii][jj]){
                if (grid[ii][jj] > t){
                    cost = grid[ii][jj] + ((grid[ii][jj] ^ t) & 1);
                }
                pushed[ii][jj] = true;
                q.push({cost, {ii, jj}});
            }
        }
        return -1;
    }
};
