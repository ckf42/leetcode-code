struct Solution {
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), lead, flip;
        vector<int> nums(m);
        for (int i = 0; i < m; ++i){
            lead = 1 << (n - 1);
            for (int j = 0; j < n; ++j){
                nums[i] |= grid[i][j] * lead;
                lead >>= 1;
            }
        }
        lead = 1 << (n - 1);
        flip = (1 << n) - 1;
        for (int &x : nums){
            if ((x & lead) == 0){
                x ^= flip;
            }
        }
        lead = 1;
        for (int j = 0; j < n; ++j){
            flip = 0;
            for (int &x : nums){
                flip += ((x & lead) != 0);
            }
            if (flip <= m / 2){
                for (int &x : nums){
                    x ^= lead;
                }
            }
            lead <<= 1;
        }
        return reduce(nums.begin(), nums.end());
    }
};
