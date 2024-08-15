#include <algorithm>

struct Solution {
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int adder = 0, currEle = nums[0], res = 0;
        for (int &n : nums){
            if (n != currEle){
                ++adder;
                currEle = n;
            }
            res += adder;
        }
        return res;
    }
};
