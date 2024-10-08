struct Solution {
    inline int findTheWinner(int n, int k) {
        int res = 1;
        for (int i = 2; i <= n; ++i){
            res = (res + k - 1) % i + 1;
        }
        return res;
    }
};
