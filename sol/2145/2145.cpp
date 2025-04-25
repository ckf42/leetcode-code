struct Solution {
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxi = 0, mini = 0, val = 0;
        for (int diff : differences){
            val += diff;
            maxi = max(maxi, val);
            mini = min(mini, val);
        }
        return max(0l, upper - lower - maxi + mini + 1);
    }
};
