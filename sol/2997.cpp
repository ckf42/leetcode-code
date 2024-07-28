struct Solution {
    inline int minOperations(vector<int>& nums, int k) {
        for (int &x : nums){
            k ^= x;
        }
        int res = 0;
        while (k != 0){
            res += k & 1;
            k >>= 1;
        }
        return res;
    }
};
