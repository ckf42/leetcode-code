struct Solution {
    using ll = long long;
    long long maximumTripletValue(vector<int>& nums) {
        ll maxVal = 0;
        int maxEle = 0, maxDiff = 0;
        for (int x : nums){
            maxVal = max(maxVal, static_cast<ll>(maxDiff) * x);
            maxDiff = max(maxDiff, maxEle - x);
            maxEle = max(maxEle, x);
        }
        return maxVal;
    }
};
