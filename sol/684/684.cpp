struct Solution {
    using Arr = array<int, 1001>;
    int getPar(int x, Arr &parents){
        while (x != parents[x]){
            int tmp = x;
            x = parents[tmp];
            parents[tmp] = parents[parents[tmp]];
        }
        return x;
    }
    void unionGp(int x, int y, Arr &par, Arr &size){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Arr parents, sizes;
        ranges::iota(parents, 0);
        sizes.fill(1);
        for (auto &r : edges){
            int x = this->getPar(r[0], parents), y = this->getPar(r[1], parents);
            if (x == y){
                return r;
            }
            this->unionGp(x, y, parents, sizes);
        }
        return {-1, -1};
    }
};
