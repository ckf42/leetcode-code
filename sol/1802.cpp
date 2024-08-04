struct Solution {
    using li = long;
    static inline li partSum(int m, int l){
        li k = min(m, l);
        return (m * 2 - k + 1) * k / 2 + l - k;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum + 1;
        while (l < r){
            int m = (l + r) / 2;
            if (this->partSum(m, index + 1) + this->partSum(m, n - index) - m <= maxSum){
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r - 1;
    }
};
