#include <numeric>

struct Solution {
    inline int finalValueAfterOperations(vector<string>& operations) {
        return std::accumulate(
            operations.begin(),
            operations.end(),
            0,
            [](int a, auto &op){return a + (op[1] == '+');}
        ) * 2 - operations.size();
    }
};
