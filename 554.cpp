#include <unordered_map>

struct Solution {
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> h;
        int l;
        h[0] = 0;
        for (auto &r : wall){
            l = 0;
            for (int i = 0; i < r.size() - 1; ++i){
                l += r[i];
                ++h[l];
            }
        }
        l = 0;
        for (auto &pr : h){
            l = max(l, pr.second);
        }
        return wall.size() - l;
    }
};
