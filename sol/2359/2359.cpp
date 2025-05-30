struct Solution {
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, n + 1);
        int dist = 0;
        vector<bool> visited(n, false);
        while (node1 != -1 && !visited[node1]){
            visited[node1] = true;
            d1[node1] = dist++;
            node1 = edges[node1];
        }
        int res = -1, minDist = n + 1;
        dist = 0;
        ranges::fill(visited, false);
        while (node2 != -1 && !visited[node2]){
            visited[node2] = true;
            int r = max(d1[node2], dist++);
            if (r < minDist || (r == minDist && node2 < res)){
                res = node2;
                minDist = r;
            }
            node2 = edges[node2];
        }
        return res;
    }
};
