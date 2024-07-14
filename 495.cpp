struct Solution {
    inline int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = 0, curr = 0, end = 0;
        for (int t : timeSeries){
            count += min(end, t) - curr;
            curr = t;
            end = t + duration;
        }
        return count + duration;
    }
};
