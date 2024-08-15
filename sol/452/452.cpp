#include <algorithm>

struct Solution {
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];});
        int res = 1, pos = points[0][1];
        for (int i = 1; i < points.size(); ++i){
            if (pos < points[i][0]){
                pos = points[i][1];
                ++res;
            }
        }
        return res;
    }
};
