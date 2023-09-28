struct Solution {
    bool isIdealPermutation(const vector<int>& nums) {
        int minToCheck = 0, thisNum;
        size_t ptr = 0, n = nums.size();
        while (ptr < n){
            thisNum = nums[ptr];
            if (thisNum == minToCheck){
                ++ptr;
                ++minToCheck;
            } else if (thisNum == minToCheck + 1 && nums[ptr + 1] == minToCheck){
                ++++ptr;
                ++++minToCheck;
            } else {
                return false;
            }
        }
        return true;
    }
};
