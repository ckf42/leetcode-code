#include <queue>

struct Solution {
    using Coor = pair<int, int>;

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0, curr = 0;
        queue<Coor> q;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    ++count;
                } else if (grid[i][j] == 2){
                    q.emplace(i, j);
                }
            }
        }
        if (count == 0){
            return 0;
        }
        while (!q.empty()){
            int s = q.size();
            while (s-- > 0){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i > 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    --count;
                    q.emplace(i - 1, j);
                }
                if (i < m - 1 && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    --count;
                    q.emplace(i + 1, j);
                }
                if (j > 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    --count;
                    q.emplace(i, j - 1);
                }
                if (j < n - 1 && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    --count;
                    q.emplace(i, j + 1);
                }
            }
            ++curr;
        }
        if (count == 0){
            return curr - 1;
        } else {
            return -1;
        }
    }
};
