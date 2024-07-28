struct Solution {
    vector<int> searchRange(const vector<int>& nums, int target) {
        size_t s = 0, e = nums.size(), m;
        vector<int> res(2, -1);
        if (e == 0){
            return res;
        }
        while (s < e){
            m = (s + e) / 2;
            if (nums[m] < target){
                s = m + 1;
            } else {
                e = m;
            }
        }
        if (s >= nums.size() || nums[s] != target){
            return res;
        }
        res[0] = s;
        s = 0, e = nums.size();
        while (s < e){
            m = (s + e) / 2;
            if (nums[m] <= target){
                s = m + 1;
            } else {
                e = m;
            }
        }
        res[1] = e - 1;
        return res;
    }
};
