struct Solution {
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int count = 0;
        for (int x : nums){
            if (x != 0){
                count = 0;
            } else {
                res += ++count;
            }
        }
        return res;
    }
};
