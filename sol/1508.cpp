#include <queue>

struct Solution {
    static constexpr int m = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ptrs(n);
        ranges::iota(ptrs, 0);
        int res = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i){
            pq.push({-nums[i], i});
        }
        for (int i = 0; i < right; ++i){
            auto [v, idx] = pq.top();
            pq.pop();
            if (i >= left - 1){
                res = (res - v) % this->m;
            }
            if (++ptrs[idx] < n){
                v -= nums[ptrs[idx]];
                pq.push({v, idx});
            }
        }
        return res;
    }
};
