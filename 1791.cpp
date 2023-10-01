#include <algorithm>

struct Solution {
    int findCenter(const vector<vector<int>>& edges) {
        if (edges[0][0] != edeges[1][0] && edges[0][0] != edeges[1][1]){
            return edges[0][1];
        } else {
            return edges[0][0];
        }
    }
};
