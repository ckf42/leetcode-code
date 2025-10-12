#include <algorithm>

struct Solution {
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        ranges::sort(potions);
        vector<int> res(n);
        for (int i = 0; i < n; ++i){
            res[i] = potions.end() - lower_bound(potions.begin(), potions.end(), (success + spells[i] - 1) / spells[i]);
        }
        return res;
    }
};
