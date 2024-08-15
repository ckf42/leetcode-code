struct Solution {
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int n = intervals.size(), i = 0, res = 0;
        while (i < n){
            int j = i + 1;
            while (j < n && intervals[j][0] < intervals[i][1]){
                ++j;
                ++res;
            }
            i = j;
        }
        return res;
    }
};
