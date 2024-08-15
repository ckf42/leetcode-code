#include <algorithm>

struct Solution {
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3, res = 0;
        for (int i = 0; i < n; i++){
            res += piles[n + (i << 1)];
        }
        return res;
    }
};
