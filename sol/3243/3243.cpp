#include <queue>

struct Solution {
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n);
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i){
            dist[i] = n - 1 - i;
            if (i != 0){
                edges[i].push_back(i - 1);
            }
        }
        int q = queries.size();
        vector<int> res(q);
        for (int i = 0; i < q; ++i){
            edges[queries[i][1]].push_back(queries[i][0]);
            queue<int> buff;
            buff.push(queries[i][1]);
            while (!buff.empty()){
                int x = buff.front();
                buff.pop();
                for (int nb : edges[x]){
                    if (dist[x] + 1 < dist[nb]){
                        dist[nb] = dist[x] + 1;
                        buff.push(nb);
                    }
                }
            }
            res[i] = dist[0];
        }
        return res;
    }
};
