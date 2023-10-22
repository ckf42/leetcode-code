#include <deque>

struct Solution {
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> recentMaxIndices;
        int maxval = nums[0];
        for (int j = 0; j < nums.size(); ++j){
            if (!recentMaxIndices.empty()){
                nums[j] += nums[recentMaxIndices.front()];
            }
            maxval = max(maxval, nums[j]);
            while (!recentMaxIndices.empty()){
                if (j - recentMaxIndices.front() >= k){
                    recentMaxIndices.pop_front();
                } else if (nums[recentMaxIndices.back()] < nums[j]){
                    recentMaxIndices.pop_back();
                } else {
                    break;
                }
            }
            if (nums[j] > 0){
                recentMaxIndices.push_back(j);
            }
        }
        return maxval;
    }
};
