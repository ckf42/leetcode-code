#include <deque>

struct Solution {
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> mst;
        int maxval = nums[0];
        for (int j = 0; j < nums.size(); ++j){
            if (!mst.empty()){
                nums[j] += nums[mst.front()];
            }
            maxval = max(maxval, nums[j]);
            while (!mst.empty() && mst.front() <= j - k){
                mst.pop_front();
            }
            while (!mst.empty() && nums[mst.back()] < nums[j]){
                mst.pop_back();
            }
            if (nums[j] > 0){
                mst.push_back(j);
            }
        }
        return maxval;
    }
};
