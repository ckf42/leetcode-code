struct Solution {
    using ll = long long;
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll right = 0, left =  grid[1][0];
        for (int i = 1; i < n; ++i){
            right += grid[0][i];
        }
        ll res = right;
        for (int i = 1; i < n; ++i){
            right -= grid[0][i];
            res = min(res, max(left, right));
            left += grid[1][i];
        }
        return res;
    }
};
