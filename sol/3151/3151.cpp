struct Solution {
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i){
            if (((nums[i] ^ nums[i + 1]) & 1) == 0){
                return false;
            }
        }
        return true;
    }
};
