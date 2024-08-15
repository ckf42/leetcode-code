struct Solution {
    int maximumScore(const vector<int>& nums, int k) {
        int maxScore = nums[k], submin = nums[k], l = k, r = k, n = nums.size();
        while (l > 0 || r < n){
            while (l > 0 && nums[l - 1] >= submin){
                --l;
            }
            while (r < n - 1 && nums[r + 1] >= submin){
                ++r;
            }
            maxScore = max(maxScore, submin * (r - l + 1));
            if (l == 0 && r == n - 1){
                break;
            }
            if (l == 0 || (r < n - 1 and nums[r + 1] > nums[l - 1])){
                submin = min(submin, nums[++r]);
            } else {
                submin = min(submin, nums[--l]);
            }
        }
        return maxScore;
    }
};
