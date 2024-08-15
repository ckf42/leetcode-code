struct Solution {
    constexpr inline int subtractProductAndSum(int n) {
        if (n == 0){
            return 0;
        }
        int sum = 0, prod = 1, r;
        while (n != 0){
            r = n % 10;
            sum += r;
            prod *= r;
            n /= 10;
        }
        return prod - sum;
    }
};
