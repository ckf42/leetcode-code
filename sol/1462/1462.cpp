#include <queue>
#include <unordered_map>
#include <unordered_set>

struct Solution {
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> edges(numCourses);
        unordered_map<int, int> indeg(numCourses);
        for (auto &e : prerequisites){
            edges[e[0]].push_back(e[1]);
            ++indeg[e[1]];
        }
        queue<int> buff;
        for (int i = 0; i < numCourses; ++i){
            if (indeg[i] == 0){
                buff.push(i);
            }
        }
        vector<unordered_set<int>> req(numCourses);
        while (!buff.empty()){
            int x = buff.front();
            buff.pop();
            for (int nb : edges[x]){
                req[nb].insert(req[x].begin(), req[x].end());
                req[nb].insert(x);
                if (--indeg[nb] == 0){
                    buff.push(nb);
                }
            }
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i){
            res[i] = req[queries[i][1]].contains(queries[i][0]);
        }
        return res;
    }
};
