struct Solution {
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 3){
            if (nums[i] > target / 4){
                break;
            }
            int j = i + 1;
            while (j < n - 2){
                int k = j + 1, l = n - 1;
                while (k < l){
                    long tot = static_cast<long>(target) - nums[i] - nums[j] - nums[k] - nums[l];
                    if (tot == 0){
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                    if (tot < 0){
                        int ll = l - 1;
                        while (ll >= 0 && nums[ll] == nums[l]){
                            --ll;
                        }
                        l = ll;
                    } else {
                        int kk = k + 1;
                        while (kk < n && nums[kk] == nums[k]){
                            ++kk;
                        }
                        k = kk;
                    }
                }
                int jj = j + 1;
                while (jj < n && nums[jj] == nums[j]){
                    ++jj;
                }
                j = jj;
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
