struct Solution {
    int alternatingSubarray(const vector<int>& nums) {
        size_t sidx = 0, n = nums.size();
        if (n < 2){
            return -1;
        }
        int maxLen = -1;
        while (true){
            while (sidx + 1 < n && nums[sidx + 1] != nums[sidx] + 1){
                ++sidx;
            }
            size_t eidx = sidx + 1;
            if (eidx == n){
                break;
            }
            bool compareToZero = true;
            int s0 = nums[sidx], s1 = nums[eidx];
            while (eidx + 1 != n && nums[eidx + 1] == (compareToZero ? s0 : s1)){
                ++eidx;
                compareToZero = !compareToZero;
            }
            maxLen = max(maxLen, static_cast<int>(eidx + 1 - sidx));
            if (eidx + 1 == n){
                break;
            }
            sidx = eidx;
        }
        return maxLen;
    }
};
