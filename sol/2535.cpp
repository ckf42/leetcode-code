struct Solution {
    inline int differenceOfSum(vector<int>& nums) {
        int res = 0;
        for (int x : nums){
            res += x;
            while (x != 0){
                res -= x % 10;
                x /= 10;
            }
        }
        return abs(res);
    }
};
