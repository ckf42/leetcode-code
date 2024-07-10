struct Solution {
    bool dfs(int x, vector<vector<int>>& graph, vector<char> &tag) {
        if (tag[x] == 1){
            return false;
        }
        if (tag[x] == 2){
            return true;
        }
        tag[x] = 1;
        for (int y : graph[x]){
            if (!dfs(y, graph, tag)){
                return false;
            }
        }
        tag[x] = 2;
        return true;
    }
    inline vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> tag(n, 0);
        vector<int> res;
        for (int i = 0; i < n; ++i){
            if (dfs(i, graph, tag)){
                res.push_back(i);
            }
        }
        return res;
    }
};
