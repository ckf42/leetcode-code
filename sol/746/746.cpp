struct Solution {
    int minCostClimbingStairs(const vector<int>& cost) {
        int dp0 = cost[0], dp1 = cost[1], temp;
        for (size_t i = 2; i < cost.size(); ++i){
            temp = cost[i] + min(dp0, dp1);
            dp0 = dp1;
            dp1 = temp;
        }
        return min(dp0, dp1);
    }
};
