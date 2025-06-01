#include <queue>

struct Solution {
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int N = n * n;
        vector<int> vallocx(N + 1), vallocy(N + 1);
        for (int x = 0; x < n; ++x){
            for (int y = 0; y < n; ++y){
                int v = x * n + y + 1;
                vallocx[v] = n - 1 - x;
                vallocy[v] = (x % 2 == 0) ? y : (n - 1 - y);
            }
        }
        vector<bool> visited(N + 1, false);
        queue<int> q;
        q.push(1);
        int d = 0;
        while (!q.empty()){
            int s = q.size();
            while (s-- > 0){
                int val = q.front();
                q.pop();
                if (val == N){
                    return d;
                }
                if (visited[val]){
                    continue;
                }
                visited[val] = true;
                for (int newv = val + 1; newv <= min(val + 6, N); ++newv){
                    int newx = vallocx[newv], newy = vallocy[newv];
                    if (board[newx][newy] == -1){
                        q.push(newv);
                    } else {
                        q.push(board[newx][newy]);
                    }
                }
            }
            ++d;
        }
        return -1;
    }
};
