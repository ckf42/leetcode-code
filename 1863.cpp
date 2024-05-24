struct Solution {
    inline int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int &x : nums){
            res |= x;
        }
        return res * (1 << (n - 1));
    }
};
