struct Solution {
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        ranges::sort(nums);
        int s = 0, e = nums[n - 1] - nums[0] + 1;
        while (s < e){
            int m = (s + e) / 2, pairCount = 0, ptr = 1;
            while (ptr < n && pairCount < p){
                if (nums[ptr] - nums[ptr - 1] <= m){
                    ++pairCount;
                    ++ptr;
                }
                ++ptr;
            }
            if (pairCount == p){
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};
