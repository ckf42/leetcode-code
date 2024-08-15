#include <queue>
#include <unordered_set>

struct Solution {
    inline bool hasIntersection(const unordered_set<int> &s1, const unordered_set<int> &s2){
        for (const int e : s1){
            if (s2.contains(e)){
                return true;
            }
        }
        return false;
    }

    int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
        if (source == target){
            return 0;
        }
        vector<unordered_set<int>> routeSet(routes.size()), edgeDict(routes.size());
        queue<pair<int, int>> q;
        unordered_set<int> endRoutes, visited;
        for (int i = 0; i < routes.size(); ++i){
            routeSet[i].insert(routes[i].cbegin(), routes[i].cend());
            for (int j = 0; j < i; ++j){
                if (this->hasIntersection(routeSet[i], routeSet[j])){
                    edgeDict[i].insert(j);
                    edgeDict[j].insert(i);
                }
            }
            if (routeSet[i].contains(source)){
                q.push(make_pair(1, i));
            }
            if (routeSet[i].contains(target)){
                endRoutes.insert(i);
            }
        }
        if (endRoutes.empty()){
            return -1;
        }
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            if (visited.contains(p.second)){
                continue;
            }
            if (endRoutes.contains(p.second)){
                return p.first;
            }
            visited.insert(p.second);
            for (const auto nei : edgeDict[p.second]){
                if (!visited.contains(nei)){
                    q.push(make_pair(p.first + 1, nei));
                }
            }
        }
        return -1;
    }
};
