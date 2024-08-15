#include <unordered_map>
#include <queue>

struct Solution {
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> edgeList;
        for (auto &e : edges){
            edgeList[e[0]].push_back(e[1]);
            edgeList[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(1);
        vector<int> visitCount(n + 1, 0), reachLvls(n + 1);
        int lvl = -1;
        while (visitCount[n] < 2){
            int s = q.size();
            while (s-- > 0){
                int u = q.front();
                q.pop();
                if (visitCount[u] != 0 && reachLvls[u] >= lvl){
                    continue;
                }
                ++visitCount[u];
                reachLvls[u] = lvl;
                if (visitCount[n] == 2){
                    break;
                }
                for (int v : edgeList[u]){
                    if (visitCount[v] < 2){
                        q.push(v);
                    }
                }
            }
            ++lvl;
        }
        int res = 0;
        while (lvl-- > 0){
            int qq = res / change;
            if (qq & 1){
                res = (qq + 1) * change;
            }
            res += time;
        }
        return res;
    }
};
