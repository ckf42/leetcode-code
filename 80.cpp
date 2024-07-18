struct Solution {
    int removeDuplicates(vector<int>& nums) {
        int occCount = 0, lastOcc = nums[0] - 1, w = 0, n = nums.size();
        for (int i = 0; i < n; ++i){
            if (nums[i] == lastOcc){
                ++occCount;
            } else {
                occCount = 1;
            }
            lastOcc = nums[i];
            if (occCount <= 2){
                nums[w++] = nums[i];
            }
        }
        return w;
    }
};
