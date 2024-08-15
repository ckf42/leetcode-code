struct Solution {
    inline long long flowerGame(int n, int m) {
        long a = n >> 1, b = m >> 1;
        return (n - a) * b + a * (m - b);
    }
};
