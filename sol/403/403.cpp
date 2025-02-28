#include <unordered_map>
#include <unordered_set>

struct Solution {
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1){
            return false;
        }
        int n = stones.size();
        if (n == 2){
            return true;
        }
        unordered_map<int, int> indices;
        for (int i = 0; i < n; ++i){
            indices[stones[i]] = i;
        }
        unordered_set<int> visited;
        vector<pair<int, int>> buff{{0, 1}};
        while (!buff.empty()){
            auto [i, j] = buff.back();
            buff.pop_back();
            if (visited.contains(i * n + j)){
                continue;
            }
            visited.insert(i * n + j);
            if (stones[j] - stones[i] > stones.back() - stones[j] + 1){
                continue;
            }
            int base = (stones[j] - stones[i]) + stones[j];
            for (int delta : {-1, 0, 1}){
                if (!indices.contains(base + delta)){
                    continue;
                }
                int k = indices[base + delta];
                if (k == n - 1){
                    return true;
                } else if (k > j){
                    buff.push_back({j, k});
                }
            }
        }
        return false;
    }
};
