#include <ranges>

struct Solution {
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<ll> freeTime(n, 0), baseDelay(n + 1, 0);
        for (int i = 0; i < n; ++i){
            baseDelay[i + 1] = baseDelay[i] + skill[i];
        }
        for (int m : mana){
            ll minStart = 0;
            for (auto [a, b] : ranges::views::zip(freeTime, baseDelay)){
                minStart = max(minStart, a - m * b);
            }
            for (int i = 0; i < n; ++i){
                freeTime[i] = minStart + m * baseDelay[i + 1];
            }
        }
        return freeTime.back();
    }
};
