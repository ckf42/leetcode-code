#include <queue>

struct Solution {
    using p = pair<int, int>;
    vector<int> findDiagonalOrder(const vector<vector<int>>& nums) {
        queue<p> q;
        q.push(make_pair(0, 0));
        vector<int> res;
        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            res.push_back(nums[i][j]);
            if (j == 0 && i < nums.size() - 1){
                q.push(make_pair(i + 1, 0));
            }
            if (j < nums[i].size() - 1){
                q.push(make_pair(i, j + 1));
            }
        }
        return res;
    }
};
