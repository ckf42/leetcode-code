struct Solution {
    int countHillValley(vector<int>& nums) {
        int res = 0, n = nums.size(), a = nums[0], ptr = 1;
        while (ptr < n && nums[ptr] == a){
            ++ptr;
        }
        if (ptr == n){
            return 0;
        }
        int b = nums[ptr];
        while (ptr < n){
            if (nums[ptr] != b){
                if ((b > a && b > nums[ptr]) || (b < a && b < nums[ptr])){
                    ++res;
                }
                a = b;
                b = nums[ptr];
            }
            ++ptr;
        }
        return res;
    }
};
