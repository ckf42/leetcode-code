struct Solution {
    vector<int> findSmallestSetOfVertices(int n, const vector<vector<int>>& edges) {
        vector<bool> arr(n, true);
        for (const vector<int> &e : edges){
            arr[e[1]] = false;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i){
            if (arr[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
