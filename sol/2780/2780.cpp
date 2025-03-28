struct Solution {
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dom = 0, vote = 0;
        for (int x : nums){
            if (vote == 0){
                dom = x;
                vote = 1;
            } else if (dom == x){
                ++vote;
            } else {
                --vote;
            }
        }
        int freq = 0;
        for (int x : nums){
            freq += x == dom;
        }
        int count = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] == dom){
                count += 2;
            }
            if (count > i + 1 && count < freq * 2 - n + i + 1){
                return i;
            }
        }
        return -1;
    }
};
