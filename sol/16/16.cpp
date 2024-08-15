struct Solution {
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = -1, diff = -1, i = 0;
        for (int i = 0; i < n - 2; ++i){
            int j = i + 1, k = n - 1;
            while (j < k){
                int tot = nums[i] + nums[j] + nums[k];
                if (tot == target){
                    return target;
                }
                int d = abs(tot - target);
                if (diff == -1 || d < diff){
                    res = tot;
                    diff = d;
                }
                if (tot > target){
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};
