struct Solution {
    int reachNumber(int target) {
        if (target < 0){
            target = -target;
        }
        long q = -1, m = (static_cast<long>(sqrt(1 + 8.0 * target)) - 2) / 2;
        while (q < 0 || (q & 3) != 0){
            ++m;
            q = m * (m + 1) - 2 * target;
        }
        return m;
    }
};
