struct Solution {
    using ll = long long;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        ranges::sort(robot);
        vector<int> fidx(m);
        ranges::iota(fidx, 0);
        ranges::sort(fidx, [&factory](int i, int j){return factory[i][0] > factory[j][0];});
        vector<ll> memo(n + 1, 0);
        int count = 0;
        for (int f = 0; f < m; ++f){
            int floc = factory[fidx[f]][0];
            for (int i = 0; i < factory[fidx[f]][1]; ++i){
                if (count < n){
                    memo[n - 1 - count] = memo[n - count] + abs(robot[n - 1 - count] - floc);
                } else {
                    memo[0] = min(memo[0], memo[1] + abs(robot[0] - floc));
                }
                for (int r = max(1, n - count); r < n; ++r){
                    memo[r] = min(memo[r], memo[r + 1] + abs(robot[r] - floc));
                }
                ++count;
            }
        }
        return memo[0];
    }
};
