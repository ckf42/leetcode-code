struct Solution {
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool seenDrop = false;
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] > nums[i + 1]){
                if (seenDrop){
                    return false;
                }
                seenDrop = true;
            }
        }
        if (seenDrop && nums.back() > nums[0]){
            return false;
        }
        return true;
    }
};
