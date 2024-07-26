#include <algorithm>

struct Solution {
    static int mapper(int x, vector<int> &mapping){
        if (x < 10){
            return mapping[x];
        }
        return mapper(x / 10, mapping) * 10 + mapping[x % 10];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> mapped(n), idx(n);
        transform(nums.begin(), nums.end(), mapped.begin(), [&mapping](int x){return mapper(x, mapping);});
        ranges::iota(idx, 0);
        ranges::stable_sort(idx, [&mapped](int i, int j){return mapped[i] < mapped[j];});
        for (int i = 0; i < n; ++i){
            mapped[i] = nums[idx[i]];
        }
        return mapped;
    }
};
