struct Solution {
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int total = prefix[n], res = 0;
        for (int i = 0; i < n; ++i){
            int a = abs(total - prefix[i] * 2);
            if (nums[i] == 0 && a <= 1){
                res += 2 - a;
            }
        }
        return res;
    }
};
