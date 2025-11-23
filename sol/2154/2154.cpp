struct Solution {
    int findFinalValue(vector<int>& nums, int original) {
        ranges::sort(nums);
        for (int x : nums){
            if (x == original){
                original *= 2;
            } else if (x > original){
                break;
            }
        }
        return original;
    }
};
