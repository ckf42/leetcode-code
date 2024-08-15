#include <unordered_set>

struct Solution {
    int getPar(int x, vector<int> &par){
        while (x != par[x]){
            int tmp = x;
            x = par[tmp];
            par[tmp] = par[par[tmp]];
        }
        return x;
    }
    inline void unionGp(int x, int y, vector<int> &par, vector<int> &size){
        x = this->getPar(x, par);
        y = this->getPar(y, par);
        if (x == y){
            return;
        }
        if (size[x] < size[y]){
            swap(x, y);
        }
        par[y] = x;
        size[x] += size[y];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> par(n, 0), size(n, 1);
        iota(par.begin(), par.end(), 0);
        for (auto &e : edges){
            this->unionGp(e[0], e[1], par, size);
        }
        unordered_set<int> heads;
        for (int i = 0; i < n; ++i){
            heads.insert(this->getPar(i, par));
        }
        long long res = 0, prefix = 0;
        for (int i : heads){
            int x = size[i];
            res += x * prefix;
            prefix += x;
        }
        return res;
    }
};
