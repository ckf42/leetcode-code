struct Solution {
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size(), cumsum = 0, ptr = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; ++i){
            cumsum += diff[i];
            while (ptr < q && cumsum < nums[i]){
                diff[queries[ptr][0]] += queries[ptr][2];
                diff[queries[ptr][1] + 1] -= queries[ptr][2];
                if (queries[ptr][0] <= i && i <= queries[ptr][1]){
                    cumsum += queries[ptr][2];
                }
                ++ptr;
            }
            if (cumsum < nums[i]){
                return -1;
            }
        }
        return ptr;
    }
};
