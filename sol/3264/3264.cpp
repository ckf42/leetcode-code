struct Solution {
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k-- > 0){
            *ranges::min_element(nums) *= multiplier;
        }
        return nums;
    }
};
