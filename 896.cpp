struct Solution {
    bool isMonotonic(const vector<int>& nums) {
        if (nums.size() <= 2){
            return true;
        }
        size_t ptr = 1, i;
        while (ptr < nums.size() && nums[ptr] == nums[ptr - 1]){
            ++ptr;
        }
        if (ptr == nums.size()){
            return true;
        }
        if (nums[ptr] > nums[ptr - 1]){
            for (i = ptr; i < nums.size() - 1; ++i){
                if (nums[i] > nums[i + 1]){
                    return false;
                }
            }
        } else {
            for (i = ptr; i < nums.size() - 1; ++i){
                if (nums[i] < nums[i + 1]){
                    return false;
                }
            }
        }
        return true;
    }
};
