struct Solution {
    int maxAbsoluteSum(vector<int>& nums) {
        int total = 0, maxi = 0, mini = 0;
        for (int x : nums){
            total += x;
            maxi = max(maxi, total);
            mini = min(mini, total);
        }
        return maxi - mini;
    }
};
