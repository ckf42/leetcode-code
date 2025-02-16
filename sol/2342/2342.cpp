#include <unordered_map>

struct Solution {
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> h;
        for (int x : nums){
            int y = x, total = 0;
            while (y != 0){
                total += y % 10;
                y /= 10;
            }
            h[total].push_back(x);
        }
        int res = -1;
        for (auto [k, v] : h){
            if (v.size() < 2){
                continue;
            }
            int max1 = -1, max2 = -1;
            for (int x : v){
                if (x > max1){
                    max2 = max1;
                    max1 = x;
                } else if (x > max2){
                    max2 = x;
                }
            }
            res = max(res, max1 + max2);
        }
        return res;
    }
};
