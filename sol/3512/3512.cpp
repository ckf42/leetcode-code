struct Solution {
    int minOperations(vector<int>& nums, int k) {
        int tot = 0;
        for (int x : nums){
            tot = (tot + x) % k;
        }
        return tot;
    }
};
