#include <ranges>

struct Solution {
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (auto [idx, w] : std::ranges::views::enumerate(words)){
            if (w.contains(x)){
                res.push_back(idx);
            }
        }
        return res;
    }
};
