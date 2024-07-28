struct Solution {
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            int a = abs(nums[i]);
            if (nums[a - 1] > 0){
                nums[a - 1] = -nums[a - 1];
            } else {
                res.push_back(a);
            }
        }
        return res;
    }
};
