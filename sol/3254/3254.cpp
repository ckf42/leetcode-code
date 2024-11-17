struct Solution {
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), i = k - 1;
        vector<int> res(n - k + 1, -1);
        while (i > 0 && nums[i - 1] + 1 == nums[i]){
            --i;
        }
        if (i == 0){
            res[0] = nums[k - 1];
        }
        for (int j = k; j < n; ++j){
            if (nums[j] != nums[j - 1] + 1){
                i = j;
            }
            if (j - i + 1 >= k){
                res[j - k + 1] = nums[j];
            }
        }
        return res;
    }
};
