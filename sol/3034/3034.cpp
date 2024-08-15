struct Solution {
    static inline bool isMatch(int i, vector<int>& nums, vector<int>& pattern){
        for (int j = 0; j < pattern.size(); ++j){
            if (pattern[j] != nums[i + j]){
                return false;
            }
        }
        return true;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), p = pattern.size();
        for (int i = 0; i < n - 1; ++i){
            nums[i] = nums[i] == nums[i + 1] ? 0 : (nums[i + 1] > nums[i] ? 1 : -1);
        }
        int res = 0, count[2] = {0, 0}, realVal[2] = {0, 0};
        for (int i = 0; i < p; ++i){
            if (nums[i] != -1){
                ++count[nums[i]];
            }
            if (pattern[i] != -1){
                ++realVal[pattern[i]];
            }
        }
        if (count[0] == realVal[0] && count[1] == realVal[1]){
            res += this->isMatch(0, nums, pattern);
        }
        for (int i = p; i < n - 1; ++i){
            if (nums[i] != -1){
                ++count[nums[i]];
            }
            if (nums[i - p] != -1){
                --count[nums[i - p]];
            }
            if (count[0] == realVal[0] && count[1] == realVal[1]){
                res += this->isMatch(i - p + 1, nums, pattern);
            }
        }
        return res;
    }
};
