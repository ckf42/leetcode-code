#include <queue>
#include <unordered_set>
#include <unordered_map>

struct Solution {
    using p = pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<p>> edges;
        for (auto &m : meetings){
            edges[m[0]].push_back({m[2], m[1]});
            edges[m[1]].push_back({m[2], m[0]});
        }
        unordered_set<int> knower;
        priority_queue<p, vector<p>, greater<p>> q;
        q.push({0, 0});
        q.push({0, firstPerson});
        while (!q.empty()){
            auto ele = q.top();
            q.pop();
            if (knower.contains(ele.second)){
                continue;
            }
            knower.insert(ele.second);
            for (auto &m : edges[ele.second]){
                if (m.first >= ele.first){
                    q.push(m);
                }
            }
        }
        return vector(knower.begin(), knower.end());
    }
};
