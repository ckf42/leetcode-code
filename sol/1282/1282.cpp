#include <unordered_map>

struct Solution {
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> d;
        vector<vector<int>> res;
        for (int i = 0; i < groupSizes.size(); ++i){
            d[groupSizes[i]].push_back(i);
            if (d[groupSizes[i]].size() == groupSizes[i]){
                res.push_back(d[groupSizes[i]]);
                d[groupSizes[i]].clear();
            }
        }
        return res;
    }
};
