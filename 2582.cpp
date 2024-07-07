struct Solution {
    inline int passThePillow(int n, int time) {
        int k = n - 1;
        time %= (k << 1);
        if (time <= n - 1){
            return time + 1;
        } else {
            return (k << 1) - time + 1;
        }
    }
};
