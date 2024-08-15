struct Solution {
    int sumOfUnique(vector<int>& nums) {
        int h[101] = {0};
        for (int x : nums){
            ++h[x];
        }
        int res = 0;
        for (int i = 1; i <= 100; ++i){
            if (h[i] == 1){
                res += i;
            }
        }
        return res;
    }
};
