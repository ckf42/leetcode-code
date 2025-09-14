struct Solution {
    int peopleAwareOfSecret(int n, int delay, int forget) {
        constexpr int m = 1e9 + 7;
        vector<int> memo(forget, 0);
        memo[0] = 1;
        int idx = 0, total = 0;
        while (n-- > 1){
            idx = (idx + forget - 1) % forget;
            total = (total + memo[(idx + delay) % forget]) % m;
            total = (total + (m - memo[idx])) % m;
            memo[idx] = total;
        }
        total = 0;
        for (int x : memo){
            total = (total + x) % m;
        }
        return total;
    }
};
