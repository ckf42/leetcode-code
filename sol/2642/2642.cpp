#include <queue>

struct Graph {
    using p = pair<int, int>;
    int n;
    vector<vector<p>> edgeDict;

    Graph(int n, const vector<vector<int>>& edges) {
        this->n = n;
        this->edgeDict.resize(n);
        for (const auto &e : edges){
            this->addEdge(e);
        }
    }
    
    inline void addEdge(const vector<int> &edge) {
        this->edgeDict[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) const {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push(make_pair(0, node1));
        vector<bool> visited(this->n, false);
        while (!pq.empty()){
            p top = pq.top();
            pq.pop();
            if (visited[top.second]){
                continue;
            }
            if (top.second == node2){
                return top.first;
            }
            visited[top.second] = true;
            for (const p &e : this->edgeDict[top.second]){
                if (!visited[e.first]){
                    pq.push(make_pair(top.first + e.second, e.first));
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
