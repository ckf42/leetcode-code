struct Solution {
    inline int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, m;
        while (s <= e){
            m = (s + e) / 2;
            if (nums[m] == target){
                return m;
            }
            bool isOnLeft = (nums[s] <= nums[m]), isSmaller = (target < nums[m]);
            if (isOnLeft){
                if (isSmaller){
                    if (target == nums[s]){
                        return s;
                    } else if (target < nums[s]){
                        s = m + 1;
                    } else {
                        e = m - 1;
                    }
                } else {
                    s = m + 1;
                }
            } else {
                if (isSmaller){
                    e = m - 1;
                } else if (target == nums[e]){
                    return e;
                } else if (target < nums[e]){
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};
