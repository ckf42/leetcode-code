struct Solution {
    using ll = long long;
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, count1 = 0;
        for (int x : nums1){
            sum1 += x;
            count1 += x == 0;
        }
        ll sum2 = 0, count2 = 0;
        for (int x : nums2){
            sum2 += x;
            count2 += x == 0;
        }
        if (count1 == 0 && count2 == 0){
            return sum1 == sum2 ? sum1 : -1;
        }
        if (count1 == 0){
            return (sum1 < sum2 + count2) ? -1 : sum1;
        }
        if (count2 == 0){
            return (sum1 + count1 > sum2) ? -1 : sum2;
        }
        return max(sum1 + count1, sum2 + count2);
    }
};
