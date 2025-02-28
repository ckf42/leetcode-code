#include <deque>

struct Solution {
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> q;
        for (int i = 0; i < k; ++i){
            while (!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        res[0] = q.front();
        for (int i = k; i < n; ++i){
            while (!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            if (q.front() == nums[i - k]){
                q.pop_front();
            }
            res[i - k + 1] = q.front();
        }
        return res;
    }
};
