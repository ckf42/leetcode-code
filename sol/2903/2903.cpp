struct Solution {
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size(), maxIdx = 0, minIdx = 0;
        for (int i = 0, j = indexDifference; i < n - indexDifference; ++i, ++j){
            if (nums[i] > nums[maxIdx]){
                maxIdx = i;
            } else if (nums[i] < nums[minIdx]){
                minIdx = i;
            }
            if (abs(nums[j] - nums[maxIdx]) >= valueDifference){
                return {maxIdx, j};
            }
            if (abs(nums[j] - nums[minIdx]) >= valueDifference){
                return {minIdx, j};
            }
        }
        return {-1, -1};
    }
};
