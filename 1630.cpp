#include <algorithm>

struct Solution {
    vector<bool> checkArithmeticSubarrays(const vector<int>& nums, const vector<int>& l, const vector<int>& r) {
        vector<bool> res(l.size(), false), checked(nums.size(), false);
        for (int ptr = 0; ptr < l.size(); ++ptr){
            const int &s = l[ptr], &e = r[ptr];
            if (e - s <= 1){
                res[ptr] = true;
                continue;
            }
            const auto [miniptr, maxiptr] = std::minmax_element(nums.cbegin() + s, nums.cbegin() + e + 1);
            if (*miniptr == *maxiptr){
                res[ptr] = true;
                continue;
            }
            int diff = (*maxiptr - *miniptr) / (e - s), r = (*maxiptr - *miniptr) % (e - s), q;
            if (r != 0){
                // res[ptr] = false;
                continue;
            }
            fill_n(checked.begin(), e - s + 1, false);
            bool yielded = false;
            for (int i = s; i <= e; ++i){
                q = (nums[i] - *miniptr) / diff, r = (nums[i] - *miniptr) % diff;
                if (r != 0){
                    // res[ptr] = false;
                    yielded = true;
                    break;
                } else {
                    checked[q] = true;
                }
            }
            if (!yielded && all_of(checked.begin(), checked.begin() + e - s + 1, [](bool v){return v;})){
                res[ptr] = true;
            }
        }
        return res;
    }
};
