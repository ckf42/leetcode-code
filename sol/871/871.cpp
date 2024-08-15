#include <queue>

struct Solution {
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if (startFuel >= target){
            return 0;
        }
        priority_queue<int> pq;
        long maxReach = startFuel;
        int maxIdx = 0;
        for (int k = 1; k <= n; ++k){
            while (maxIdx < n && stations[maxIdx][0] <= maxReach){
                pq.push(stations[maxIdx++][1]);
            }
            if (pq.empty()){
                return -1;
            }
            maxReach += pq.top();
            pq.pop();
            if (maxReach >= target){
                return k;
            }
        }
        return -1;
    }
};
