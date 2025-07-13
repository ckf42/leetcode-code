struct Solution {
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), prev  = 0;
        vector<int> gaps(n + 1);
        for (int i = 0; i < n; ++i){
            gaps[i] = startTime[i] - prev;
            prev = endTime[i];
        }
        gaps[n] = eventTime - prev;
        int w = 0;
        for (int i = 0; i <= k; ++i){
            w += gaps[i];
        }
        int res = w;
        for (int i = k + 1; i <= n; ++i){
            w += gaps[i] - gaps[i - k - 1];
            res = max(res, w);
        }
        return res;
    }
};
