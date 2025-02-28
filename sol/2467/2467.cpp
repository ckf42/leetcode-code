#include <unordered_map>
#include <queue>

struct Solution {
    static constexpr int c_NOTVISITED = -2e9;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<bool> bobed(n, false);
        bobed[bob] = true;
        unordered_map<int, vector<int>> treeEdges;
        for (auto &e : edges){
            treeEdges[e[0]].push_back(e[1]);
            treeEdges[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1);
        parent[0] = 0;
        queue<int> buff;
        buff.push(0);
        while (!buff.empty()){
            int s = buff.size();
            while (s-- > 0){
                int node = buff.front();
                buff.pop();
                for (int nb : treeEdges[node]){
                    if (parent[nb] != -1){
                        continue;
                    }
                    parent[nb] = node;
                    buff.push(nb);
                }
            }
        }
        vector<int> aTotal(n, c_NOTVISITED);
        aTotal[0] = amount[0];
        buff.push(0);
        int res = c_NOTVISITED;
        while (!buff.empty()){
            bob = parent[bob];
            bobed[bob] = true;
            int s = buff.size();
            while (s-- > 0){
                int node = buff.front();
                buff.pop();
                for (int nb : treeEdges[node]){
                    if (nb == parent[node]){
                        continue;
                    }
                    aTotal[nb] = aTotal[node];
                    if (nb == bob){
                        aTotal[nb] += amount[nb] / 2;
                    } else if (!bobed[nb]){
                        aTotal[nb] += amount[nb];
                    }
                    if (treeEdges[nb].size() == 1){
                        res = max(res, aTotal[nb]);
                    } else {
                        buff.push(nb);
                    }
                }
            }
        }
        return res;
    }
};
