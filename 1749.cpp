struct Solution {
    inline int maxAbsoluteSum(vector<int>& nums) {
        int p = 0, n = 0, cp = 0, cn = 0;
        for (int x : nums){
            cp = max(0, cp + x);
            cn = max(0, cn - x);
            p = max(p, cp);
            n = max(n, cn);
        }
        return max(p, n);
    }
};
