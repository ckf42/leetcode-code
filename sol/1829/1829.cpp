struct Solution {
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> res(n, 0);
        res[n - 1] = ((1 << maximumBit) - 1) ^ nums[0];
        for (int i = n - 2; i >= 0; --i){
            res[i] = res[i + 1] ^ nums[n - 1 - i];
        }
        return res;
    }
};
