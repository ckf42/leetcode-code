#include <algorithm>

struct Solution {
    int findCenter(vector<vector<int>>& edges) {
        if (find(edges[1].cbegin(), edges[1].cend(), edges[0][0]) != edges[1].cend()){
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
