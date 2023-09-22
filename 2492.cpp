#include <utility>

struct Solution {
    int minScore(int n, const vector<vector<int>>& roads) {
        vector<pair<int, int>> edges[n];
        int maxCost = -1;
        for (size_t eidx = 0; eidx < roads.size(); ++eidx){
            edges[roads[eidx][0] - 1].push_back(pair<int, int>(roads[eidx][1], eidx));
            edges[roads[eidx][1] - 1].push_back(pair<int, int>(roads[eidx][0], eidx));
            maxCost = max(maxCost, roads[eidx][2]);
        }
        vector<bool> visitedNode(n, false), visitedEdge(roads.size(), false);
        stack<int> st;
        st.push(1);
        while (!st.empty()){
            int pt = st.top();
            st.pop();
            if (visitedNode[pt - 1]){
                continue;
            }
            visitedNode[pt - 1] = true;
            for (const pair<int, int> pr : edges[pt - 1]){
                if (!visitedEdge[pr.second]){
                    visitedEdge[pr.second] = true;
                    st.push(pr.first);
                }
            }
        }
        int minVal = maxCost;
        for (size_t eidx = 0; eidx < roads.size(); ++eidx){
            if (visitedEdge[eidx]){
                minVal = min(minVal, roads[eidx][2]);
            }
        }
        return minVal;
    }
};
