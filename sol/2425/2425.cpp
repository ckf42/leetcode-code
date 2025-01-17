struct Solution {
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        if (nums1.size() & 1){
            for (int x : nums2){
                res ^= x;
            }
        }
        if (nums2.size() & 1){
            for (int x : nums1){
                res ^= x;
            }
        }
        return res;
    }
};
