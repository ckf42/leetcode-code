struct Solution {
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; --i){
            if (-nums[l] > nums[r]){
                res[i] = nums[l] * nums[l];
                ++l;
            } else {
                res[i] = nums[r] * nums[r];
                --r;
            }
        }
        return res;
    }
};
