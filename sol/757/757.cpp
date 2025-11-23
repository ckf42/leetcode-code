struct Solution {
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        ranges::sort(intervals, ranges::less{}, [](auto &a){return make_pair(a[1], -a[0]);});
        int res = 2, b = intervals[0][1];
        int a = b - 1;
        for (int i = 1; i < n; ++i){
            int c = intervals[i][0], d = intervals[i][1];
            if (c > b){
                ++++res;
                a = d - 1;
                b = d;
            } else if (c > a){
                ++res;
                a = b;
                b = d;
            }
        }
        return res;
    }
};
