#include <unordered_map>

struct Solution {
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        int m = n >> 1;
        ranges::sort(nums);
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; ++i){
            indices[nums[i]].push_back(i);
        }
        for (int i = 1; i < n; ++i){
            int k = nums[i] - nums[0];
            if (k == 0 || (k & 1) != 0){
                continue;
            }
            k >>= 1;
            vector<bool> paired(n, false);
            paired[0] = true;
            paired[i] = true;
            vector<int> res(1, nums[0] + k);
            for (int j = 1; j < n; ++j){
                if (paired[j]){
                    continue;
                }
                for (int idx : indices[nums[j] + k * 2]){
                    if (!paired[idx]){
                        res.push_back(nums[j] + k);
                        paired[j] = true;
                        paired[idx] = true;
                        break;
                    }
                }
                if (!paired[j]){
                    break;
                }
            }
            if (res.size() == m){
                return res;
            }
        }
        return {};
    }
};
