#include <unordered_map>

struct Solution {
    inline bool checkSubarraySum(vector<int>& nums, int k) {
        const int &n = nums.size();
        if (n < 2){
            return false;
        }
        unsigned prefix = 0;
        unordered_map<unsigned, int> d;
        d.insert({0, -1});
        for (int i = 0; i < n; ++i){
            prefix = (prefix + nums[i]) % k;
            auto iter = d.find(prefix);
            if (iter == d.end()){
                d.insert({prefix, i});
            } else if (iter->second != i - 1){
                return true;
            }
        }
        return false;
    }
};
