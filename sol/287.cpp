struct Solution {
    int findDuplicate(vector<int>& nums) {
        int tort = nums[0], hare = nums[nums[0]];
        while (tort != hare){
            tort = nums[tort];
            hare = nums[nums[hare]];
        }
        tort = 0;
        while (tort != hare){
            tort = nums[tort];
            hare = nums[hare];
        }
        return tort;
    }
};
