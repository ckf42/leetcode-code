#include <queue>

struct Solution {
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1);
        prefix[0] = 0;
        deque<int> q;
        q.push_back(0);
        int res = n + 1;
        for (int i = 0; i < n; ++i){
            long x = prefix[i + 1] = prefix[i] + nums[i];
            while (!q.empty() && prefix[q.front()] <= x - k){
                res = min(res, i - q.front() + 1);
                q.pop_front();
            }
            while (!q.empty() && prefix[q.back()] >= x){
                q.pop_back();
            }
            q.push_back(i + 1);
        }
        return res > n ? -1 : res;
    }
};
