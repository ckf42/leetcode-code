struct Solution {
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pptr = 0, nptr = 0;
        vector<int> pos(n >> 1, 0), neg(n >> 1, 0);
        for (int i = 0; i < n; ++i){
            if (nums[i] > 0){
                pos[pptr++] = nums[i];
            } else {
                neg[nptr++] = nums[i];
            }
        }
        for (int i = 0; i < n; ++i){
            nums[i] = (i & 1) ? neg[i >> 1] : pos[i >> 1];
        }
        return nums;
    }
};
