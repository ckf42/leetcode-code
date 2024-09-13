struct Solution {
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> prefix(n + 1, 0);
        prefix[1] = arr[0];
        for (int i = 2; i <= n; ++i){
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        vector<int> res(q, 0);
        for (int i = 0; i < q; ++i){
            res[i] = prefix[queries[i][0]] ^ prefix[queries[i][1] + 1];
        }
        return res;
    }
};
