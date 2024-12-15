#include <deque>

struct Solution {
    using ll = long long;
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), e = 0;
        ll res = 0;
        deque<int> stDec, stInc;
        for (int s = 0; s < n; ++s){
            while (e < n){
                while (!stDec.empty() && nums[stDec.back()] <= nums[e]){
                    stDec.pop_back();
                }
                stDec.push_back(e);
                while (!stInc.empty() && nums[stInc.back()] >= nums[e]){
                    stInc.pop_back();
                }
                stInc.push_back(e);
                if (nums[stDec.front()] - nums[stInc.front()] > 2){
                    break;
                }
                ++e;
            }
            res += e - s;
            if (stDec.front() == s){
                stDec.pop_front();
            }
            if (stInc.front() == s){
                stInc.pop_front();
            }
        }
        return res;
    }
};
