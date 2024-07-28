#include <stack>
#include <unordered_map>

struct Solution {
    int minimumTime(int n, const vector<vector<int>>& relations, const vector<int>& time) {
        unordered_multimap<int, int> edgeDict;
        vector<int> indegree(n, 0), preReqTime(n, 0);
        stack<int> st;
        for (const vector<int> &e : relations){
            edgeDict.insert(make_pair(e[0] - 1, e[1] - 1));
            ++indegree[e[1] - 1];
        }
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 0){
                st.push(i);
            }
        }
        int res = -1, node, nei, timeCost;
        while (!st.empty()){
            node = st.top();
            st.pop();
            timeCost = preReqTime[node] + time[node];
            res = max(res, timeCost);
            auto rg = edgeDict.equal_range(node);
            for (auto it = rg.first; it != rg.second; ++it){
                nei = it->second;
                preReqTime[nei] = max(preReqTime[nei], timeCost);
                if (--indegree[nei] == 0){
                    st.push(nei);
                }
            }
        }
        return res;
    }
};
