struct Solution {
    int countDays(int days, vector<vector<int>>& meetings) {
        ranges::sort(meetings, [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        int res = 0, currDay = 1;
        for (auto &itv : meetings){
            if (currDay < itv[0]){
                res += itv[0] - currDay;
            }
            currDay = max(currDay, itv[1] + 1);
        }
        if (currDay <= days){
            res += days - currDay + 1;
        }
        return res;
    }
};
