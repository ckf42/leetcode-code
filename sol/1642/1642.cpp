#include <queue>

struct Solution {
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long required = 0;
        priority_queue<int, vector<int>, std::greater<int>> h;
        for (int i = 0; i < heights.size() - 1; ++i){
            int j = heights[i + 1] - heights[i];
            if (j <= 0){
                continue;
            }
            if (h.size() < ladders){
                h.push(j);
            } else if (ladders == 0 || h.top() >= j){
                required += j;
            } else {
                required += h.top();
                h.pop();
                h.push(j);
            }
            if (required > bricks){
                return i;
            }
        }
        return heights.size() - 1;
    }
};
