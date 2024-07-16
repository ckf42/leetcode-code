#include <unordered_set>

struct Solution {
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        while (!s.empty()){
            int l = 1, x = *s.begin();
            s.erase(s.begin());
            int y = x;
            while (y < 2147483647 && s.contains(y + 1)){
                ++y;
                ++l;
                s.erase(y);
            }
            y = x;
            while (y > -2147483648 && s.contains(y - 1)){
                --y;
                ++l;
                s.erase(y);
            }
            res = max(res, l);
        }
        return res;
    }
};
