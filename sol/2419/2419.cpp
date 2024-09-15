struct Solution {
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxele = nums[0], maxlen = 1;
        int currele = maxele, currlen = 1;
        for (int i = 1; i < n; ++i){
            if (nums[i] == currele){
                ++currlen;
            } else {
                currele = nums[i];
                currlen = 1;
            }
            if (currele > maxele || (currele == maxele && currlen > maxlen)){
                maxele = currele;
                maxlen = currlen;
            }
        }
        return maxlen;
    }
};
