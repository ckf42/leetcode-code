struct Solution {
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        ranges::sort(events, [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        vector<pair<int, int>> maxVal;
        maxVal.push_back({events[n - 1][0], events[n - 1][2]});
        for (int i = n - 2; i >= 0; --i){
            if (events[i][2] > maxVal.back().second){
                maxVal.push_back({events[i][0], events[i][2]});
            }
        }
        ranges::sort(events, [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];});
        int ptr = maxVal.size() - 1, res = 0;
        for (auto &e : events){
            res = max(res, e[2]);
            while (ptr >= 0 && maxVal[ptr].first <= e[1]){
                --ptr;
            }
            if (ptr >= 0){
                res = max(res, e[2] + maxVal[ptr].second);
            }
        }
        return res;
    }
};
