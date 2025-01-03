#include <algorithm>

struct Solution {
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> memo(n + 1);
        memo[0] = 0;
        for (int i = 0; i < n; ++i){
            memo[i + 1] = std::min({
                memo[i] + costs[0],
                memo[std::lower_bound(days.begin(), days.begin() + i, days[i] - 6) - days.begin()] + costs[1],
                memo[std::lower_bound(days.begin(), days.begin() + i, days[i] - 29) - days.begin()] + costs[2]
            });
        }
        return memo[n];
    }
};
