#include <unordered_set>

struct Solution {
    inline int d(vector<int> &p1, vector<int> &p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<int> notReached;
        vector<pair<int, int>> h(n - 1);
        for (int i = 1; i < n; ++i){
            notReached.insert(notReached.end(), i);
            h[i - 1] = {-this->d(points[0], points[i]), i};
        }
        ranges::make_heap(h);
        int cost = 0;
        for (int t = 0; t < n - 1; ++t){
            while (!notReached.contains(h.front().second)){
                ranges::pop_heap(h);
                h.pop_back();
            }
            auto [w, i] = h.front();
            ranges::pop_heap(h);
            h.pop_back();
            notReached.erase(i);
            cost -= w;
            for (int j : notReached){
                h.push_back({-this->d(points[i], points[j]), j});
                ranges::push_heap(h);
            }
        }
        return cost;
    }
};
