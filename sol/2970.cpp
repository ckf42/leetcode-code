struct Solution {
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return 1;
        }
        vector<bool> isPre(n, false), isPost(n, false);
        isPre[0] = true; isPre[1] = true;
        for (int i = 2; i < n; ++i){
            if (nums[i - 1] <= nums[i - 2]){
                break;
            }
            isPre[i] = true;
        }
        isPost[n - 1] = true; isPost[n - 2] = true;
        for (int i = n - 3; i >= 0; --i){
            if (nums[i + 1] >= nums[i + 2]){
                break;
            }
            isPost[i] = true;
        }
        int res = 0;
        for (int i = 0; i < n; ++i){
            if (!isPre[i]){
                continue;
            }
            for (int j = i; j < n; ++j){
                if (isPost[j]){
                    res += i == 0 || j == n - 1 || nums[i - 1] < nums[j + 1];
                }
            }
        }
        return res;
    }
};
