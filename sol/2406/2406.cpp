struct Solution {
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> idx(intervals.size());
        ranges::iota(idx, 0);
        ranges::sort(idx, [&intervals](int i, int j){
            return intervals[i][0] < intervals[j][0];
        });
        vector<int> h;
        int res = 0;
        for (int i : idx){
            int s = intervals[i][0], e = intervals[i][1];
            if (h.empty() || -h[0] >= s){
                ++res;
                h.push_back(-e);
            } else {
                ranges::pop_heap(h);
                h.back() = -e;
            }
            ranges::push_heap(h);
        }
        return res;
    }
};
