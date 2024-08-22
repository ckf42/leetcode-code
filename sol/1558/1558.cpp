struct Solution {
    int minOperations(vector<int>& nums) {
        int res = 0, maxl = 0;
        for (int x : nums){
            if (x == 0){
                continue;
            }
            res += popcount(static_cast<unsigned>(x));
            int l = -1;
            while (x != 0){
                ++l;
                x >>= 1;
            }
            maxl = max(maxl, l);
        }
        return res + maxl;
    }
};
