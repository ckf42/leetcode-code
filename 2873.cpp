struct Solution {
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0;
        int maxDiff = 0, maxNum = 0;
        for (int n: nums){
            maxVal = max(maxVal, maxDiff * static_cast<long long>(n));
            maxDiff = max(maxDiff, maxNum - n);
            maxNum = max(maxNum, n);
        }
        return maxVal;
    }
};
