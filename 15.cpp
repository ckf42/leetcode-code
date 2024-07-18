struct Solution {
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 2){
            if (nums[i] > 0){
                break;
            }
            int j = i + 1, k = n - 1;
            while (j < k){
                int tot = nums[i] + nums[j] + nums[k];
                if (tot == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                }
                if (tot > 0){
                    int kk = k - 1;
                    while (kk >= 0 && nums[kk] == nums[k]){
                        --kk;
                    }
                    k = kk;
                } else {
                    int jj = j + 1;
                    while (jj < n && nums[jj] == nums[j]){
                        ++jj;
                    }
                    j = jj;
                }
            }
            int ii = i + 1;
            while (ii < n && nums[ii] == nums[i]){
                ++ii;
            }
            i = ii;
        }
        return res;
    }
};
