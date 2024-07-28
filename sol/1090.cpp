#include <unordered_map>

struct Solution {
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int, vector<int>> bucket;
        int n = values.size();
        for (int i = 0; i < n; ++i){
            bucket[labels[i]].push_back(values[i]);
        }
        vector<int> cont;
        for (auto &[l, b] : bucket){
            ranges::sort(b, std::greater<int>{});
            int nn = min(useLimit, static_cast<int>(b.size()));
            cont.insert(cont.end(), b.begin(), b.begin() + nn);
        }
        ranges::sort(cont, std::greater<int>{});
        int res = 0;
        for (int i = 0; i < min(numWanted, static_cast<int>(cont.size())); ++i){
            res += cont[i];
        }
        return res;
    }
};
