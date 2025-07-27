struct Solution {
    int maxSum(vector<int>& nums) {
        bool seen[101] = {false};
        int m = -101, tot = 0;
        for (int x : nums){
            m = max(m, x);
            if (x >= 0 && !seen[x]){
                seen[x] = true;
                tot += x;
            }
        }
        if (m < 0){
            return m;
        }
        return tot;
    }
};
