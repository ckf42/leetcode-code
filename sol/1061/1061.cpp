#include <ranges>

struct Solution {
    using Par = array<int, 26>;
    int getParent(int x, Par &parent){
        while (parent[x] != x){
            int temp = parent[x];
            parent[x] = parent[temp];
            x = temp;
        }
        return x;
    }
    void unionGp(int x, int y, Par &parent){
        x = this->getParent(x, parent);
        y = this->getParent(y, parent);
        if (x == y){
            return;
        }
        if (x > y){
            swap(x, y);
        }
        parent[y] = x;
    }
    string smallestEquivalentString(const string &s1, const string &s2, string baseStr) {
        Par parent;
        ranges::iota(parent, 0);
        for (auto [a, b] : ranges::views::zip(s1, s2)){
            this->unionGp(a - 'a', b - 'a', parent);
        }
        ranges::transform(baseStr, baseStr.begin(), [&](char c){return this->getParent(c - 'a', parent) + 'a';});
        return baseStr;
    }
};
