#include <ranges>

struct Solution {
    int compareVersion(string_view version1, string_view version2) {
        auto n1 = version1 
                | ranges::views::split('.') 
                | ranges::views::transform([](auto s){return std::stoi(string(s.data()));}) 
                | ranges::to<std::vector>(),
             n2 = version2 
                | ranges::views::split('.') 
                | ranges::views::transform([](auto s){return std::stoi(string(s.data()));}) 
                | ranges::to<std::vector>();
        if (n1.size() < n2.size()){
            n1.insert(n1.end(), n2.size() - n1.size(), 0);
        } else if (n1.size() > n2.size()){
            n2.insert(n2.end(), n1.size() - n2.size(), 0);
        }
        for (auto [a, b] : ranges::views::zip(n1, n2)){
            if (a < b){
                return -1;
            }
            if (a > b){
                return 1;
            }
        }
        return 0;
    }
};
