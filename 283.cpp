struct Solution {
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator ptr = nums.begin();
        for (int &n : nums){
            if (n != 0){
                swap(n, *ptr);
                ++ptr;
            }
        }
    }
};
