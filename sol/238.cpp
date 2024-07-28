struct Solution {
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int p = 1;
        for (int i = 1; i < nums.size(); ++i){
            p *= nums[i - 1];
            res[i] *= p;
        }
        p = 1;
        for (int i = nums.size() - 2; i >= 0; --i){
            p *= nums[i + 1];
            res[i] *= p;
        }
        return res;
    }
};
