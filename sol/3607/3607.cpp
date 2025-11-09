struct Solution {
    using vi = vector<int>;
    int get(int x, vi &par){
        int p;
        while ((p = par[x]) != x){
            par[x] = par[p];
            x = p;
        }
        return x;
    }
    void unionGp(int x, int y, vi &par, vi &size){
        x = this->get(x, par);
        y = this->get(y, par);
        if (x == y){
            return;
        }
        if (size[x] < size[y]){
            swap(x, y);
        }
        par[y] = x;
        size[x] += size[y];
    }
    vector<int> processQueries(
            int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vi par(c + 1), size(c + 1, 1);
        ranges::iota(par, 0);
        for (auto &e : connections){
            this->unionGp(e[0], e[1], par, size);
        }
        unordered_map<int, vi> hs;
        for (int i = 1; i <= c; ++i){
            int p = this->get(i, par);
            hs[p].push_back(-i);
            ranges::push_heap(hs[p]);
        }
        vector<bool> isOn(c + 1, true);
        vi res;
        for (auto &q : queries){
            if (q[0] == 2){
                isOn[q[1]] = false;
            } else if (isOn[q[1]]){
                res.push_back(q[1]);
            } else {
                int p = this->get(q[1], par);
                while (!hs[p].empty() && !isOn[-hs[p][0]]){
                    ranges::pop_heap(hs[p]);
                    hs[p].pop_back();
                }
                res.push_back(hs[p].empty() ? -1 : -hs[p][0]);
            }
        }
        return res;
    }
};
