#include <queue>

struct Solution {
    static constexpr array<pair<int, int>, 4> DIRS = {{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    }};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!pq.empty()){
            auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1){
                return -t;
            }
            if (visited[x][y]){
                continue;
            }
            visited[x][y] = true;
            for (auto [dx, dy] : this->DIRS){
                int xx = x + dx, yy = y + dy;
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy]){
                    pq.push({min(t, -moveTime[xx][yy]) - 1, xx, yy});
                }
            }
        }
        return -1;
    }
};
