struct Solution {
    inline int getPar(int x, vector<int> &parent){
        while (parent[x] != x){
            int y = x;
            x = parent[y];
            parent[y] = parent[x];
        }
        return x;
    }
    inline void unionGp(int x, int y, int w, vector<int> &parent, vector<int> &size, vector<int> &cost){
        x = this->getPar(x, parent);
        y = this->getPar(y, parent);
        cost[x] &= w;
        if (x == y){
            return;
        }
        if (size[x] < size[y]){
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        cost[x] &= cost[y];
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n), size(n, 1), cost(n, 0xfffff);
        ranges::iota(parent, 0);
        for (auto &e : edges){
            this->unionGp(e[0], e[1], e[2], parent, size, cost);
        }
        int q = query.size();
        vector<int> res(q);
        for (int i = 0; i < q; ++i){
            int s = this->getPar(query[i][0], parent),
                t = this->getPar(query[i][1], parent);
            if (s != t){
                res[i] = -1;
            } else {
                res[i] = cost[s];
            }
        }
        return res;
    }
};
