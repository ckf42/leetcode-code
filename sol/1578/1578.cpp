#include <ranges>

struct Solution {
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, maxt = 0;
        char prev = '\0';
        for (auto [c, t] : ranges::zip_view(colors, neededTime)){
            if (c == prev){
                if (t > maxt){
                    swap(t, maxt);
                }
                res += t;
            } else {
                prev = c;
                maxt = t;
            }
        }
        return res;
    }
};
