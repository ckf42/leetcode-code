struct Solution {
    inline int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), w = 1;
        for (int i = 1; i < n; ++i){
            if (nums[i] != nums[w - 1]){
                nums[w++] = nums[i];
            }
        }
        return w;
    }
};
