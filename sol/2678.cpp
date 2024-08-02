#include <ranges>

struct Solution {
    int countSeniors(vector<string>& details) {
        return ranges::fold_left(
            details | ranges::views::transform(
                [](string &s){
                    return s[11] * 10 + s[12] > 60 + '0' * 11;
                }
            ), 
            0, 
            std::plus<int>{}
        );
    }
};
