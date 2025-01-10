#include <unordered_map>

struct Solution {
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> total;
        for (string w : words2){
            ranges::sort(w);
            int s = 0, e;
            while (s != w.size()){
                e = s + 1;
                while (e < w.size() && w[e] == w[s]){
                    ++e;
                }
                total[w[s]] = max(total[w[s]], e - s);
                s = e;
            }
        }
        vector<string> res;
        for (const auto &w : words1){
            bool shouldAdd = true;
            for (auto [c, freq] : total){
                if (ranges::count(w, c) < freq){
                    shouldAdd = false;
                    break;
                }
            }
            if (shouldAdd){
                res.push_back(w);
            }
        }
        return res;
    }
};
