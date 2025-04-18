#include <unordered_map>

struct Solution {
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> locs;
        int res = 0;
        for (int j = 0; j < nums.size(); ++j){
            for (int i : locs[nums[j]]){
                if (i * j % k == 0){
                    ++res;
                }
            }
            locs[nums[j]].push_back(j);
        }
        return res;
    }
};
