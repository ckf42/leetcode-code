struct Solution {
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto &q : queries){
            ++diff[q[0]];
            --diff[q[1] + 1];
        }
        int cumsum = 0;
        for (int i = 0; i < n; ++i){
            cumsum += diff[i];
            if (cumsum < nums[i]){
                return false;
            }
        }
        return true;
    }
};
