struct Solution {
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        for (int x : nums){
            if (x < 0){
                x = -x - 1;
            }
            if (nums[x] < 0){
                res.push_back(x);
            } else {
                nums[x] = -nums[x] - 1;
            }
        }
        return res;
    }
};
