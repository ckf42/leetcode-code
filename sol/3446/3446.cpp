#include <ranges>

struct Solution {
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d : ranges::views::iota(0, n + 1)){
            ranges::sort(
                ranges::views::iota(0, n - d)
                    | ranges::views::transform([&](int j) -> int& {return grid[j + d][j];}),
                std::greater{}
            );
        }
        for (int d : ranges::views::iota(1, n + 1)){
            ranges::sort(
                ranges::views::iota(0, n - d)
                    | ranges::views::transform([&](int i) -> int& {return grid[i][i + d];}),
                {}
            );
        }
        return grid;
    }
};
