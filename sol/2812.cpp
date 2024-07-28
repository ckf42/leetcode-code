#include <queue>

struct Solution {
    using pr = pair<int, pair<int, int>>;

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 && grid[n - 1][n - 1] == 1){
            return 0;
        }
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pr> q;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    q.push({0, {i, j}});
                }
            }
        }
        while (!q.empty()){
            pr e = q.front();
            q.pop();
            if (dist[e.second.first][e.second.second] != -1){
                continue;
            }
            dist[e.second.first][e.second.second] = e.first;
            if (e.second.first > 0){ q.push({e.first + 1, {e.second.first - 1, e.second.second}}); }
            if (e.second.first < n - 1){ q.push({e.first + 1, {e.second.first + 1, e.second.second}}); }
            if (e.second.second > 0){ q.push({e.first + 1, {e.second.first, e.second.second - 1}}); }
            if (e.second.second < n - 1){ q.push({e.first + 1, {e.second.first, e.second.second + 1}}); }
        }
        priority_queue<pr> pq;
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()){
            pr e = pq.top();
            pq.pop();
            if (e.second.first == n - 1 && e.second.second == n - 1){
                return e.first;
            }
            if (grid[e.second.first][e.second.second] == -1){
                continue;
            }
            grid[e.second.first][e.second.second] = -1;
            if (e.second.first > 0){
                pq.push({min(e.first, dist[e.second.first - 1][e.second.second]), {e.second.first - 1, e.second.second}}); 
            }
            if (e.second.first < n - 1){
                pq.push({min(e.first, dist[e.second.first + 1][e.second.second]), {e.second.first + 1, e.second.second}});
            }
            if (e.second.second > 0){
                pq.push({min(e.first, dist[e.second.first][e.second.second - 1]), {e.second.first, e.second.second - 1}});
            }
            if (e.second.second < n - 1){
                pq.push({min(e.first, dist[e.second.first][e.second.second + 1]), {e.second.first, e.second.second + 1}}); 
            }
        }
        return -1;
    }
};
