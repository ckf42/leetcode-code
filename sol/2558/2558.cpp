#include <cmath>

struct Solution {
    using ll = long long;
    long long pickGifts(vector<int>& gifts, int k) {
        ranges::make_heap(gifts);
        while (k-- > 0 && !gifts.empty()){
            ranges::pop_heap(gifts);
            gifts.back() = static_cast<int>(std::sqrt(gifts.back()));
            ranges::push_heap(gifts);
        }
        ll total = 0;
        for (int x : gifts){
            total += x;
        }
        return total;
    }
};
