struct Solution {
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), x = 0;
        vector<bool> res(n);
        for (int i = 0; i < n; ++i){
            x <<= 1;
            x |= nums[i];
            x %= 5;
            res[i] = x == 0;
        }
        return res;
    }
};
