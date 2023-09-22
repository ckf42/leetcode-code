#include <algorithm>

struct Solution {
    int maxStarSum(const vector<int>& vals, const vector<vector<int>>& edges, const int& k) {
        vector<vector<int>> nbVals;
        nbVals.resize(vals.size());
        for (auto it = edges.cbegin(); it != edges.cend(); ++it){
            int pt0 = it->at(0), pt1 = it->at(1);
            if (vals[pt1] > 0){
                nbVals[pt0].push_back(vals[pt1]);
            }
            if (vals[pt0] > 0){
                nbVals[pt1].push_back(vals[pt0]);
            }
        }
        int maxVal = vals[0];
        for (size_t i = 0; i < vals.size(); ++i){
            sort(nbVals[i].begin(), nbVals[i].end());
            int sum = vals[i];
            for (size_t j = 0; j < min(static_cast<size_t>(k), nbVals[i].size()); ++j){
                sum += nbVals[i][nbVals[i].size() - 1 - j];
            }
            maxVal = max(maxVal, sum);
        }
        return maxVal;
    }
};
