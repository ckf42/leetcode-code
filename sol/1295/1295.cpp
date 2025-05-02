#include <ranges>

struct Solution {
    int findNumbers(vector<int>& nums) {
        return ranges::fold_left(
                nums 
                | std::ranges::views::transform([](int i){return (to_string(i).size() & 1) == 0;}),
                0,
                std::plus{}
            );
    }
};
