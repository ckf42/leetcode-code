struct Solution {
    int longestAlternatingSubarray(const vector<int>& nums, int threshold) {
        if (nums.size() == 1){
            if (nums[0] > threshold || (nums[0] & 1)){
                return 0;
            } else {
                return 1;
            }
        }
        size_t l = 0, maxlen = 0, r;
        while (true){
            while (l < nums.size() && (nums[l] > threshold || (nums[l] & 1))){
                ++l;
            }
            if (l == nums.size()){
                break;
            }
            r = l + 1;
            while (r < nums.size() && nums[r] <= threshold && (nums[r] & 1) != (nums[r - 1] & 1)){
                ++r;
            }
            maxlen = max(maxlen, r - l);
            if (r == nums.size()){
                break;
            }
            l = r;
        }
        return maxlen;
    }
};
