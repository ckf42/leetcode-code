struct Solution {
    inline int missingNumber(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it){
            s += *it;
        }
        return n * (n + 1) / 2 - s;
    }
};
