struct Solution {
    inline int minPatches(const vector<int>& nums, int n) {
        int res = 0, ptr = 0;
        unsigned reach = 0;
        while (reach < n){
            if (ptr < nums.size() && reach >= nums[ptr] - 1){
                reach += nums[ptr++];
            } else {
                reach <<= 1;
                ++reach;
                ++res;
            }
        }
        return res;
    }
};
