#include <unordered_map>

struct Solution {
    int findMaxLength(vector<int>& nums) {
        int p = 0, res = 0;
        unordered_map<int, int> idx{{0, -1}};
        for (int i = 0; i < nums.size(); ++i){
            p += (nums[i] == 1 ? 1 : -1);
            if (!idx.contains(p)){
                idx[p] = i;
            } else {
                res = max(res, i - idx[p]);
            }
        }
        return res;
    }
};
