struct Solution {
    inline int getPar(int x, vector<int> &parent){
        while (x != parent[x]){
            int y = x;
            x = parent[y];
            parent[y] = parent[parent[y]];
        }
        return x;
    }
    inline void unionGp(int x, int y, vector<int> &parent, vector<int> &size){
        x = this->getPar(x, parent);
        y = this->getPar(y, parent);
        if (x == y){
            return;
        }
        if (size[x] < size[y]){
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> parent(n), size(n, 1);
        ranges::iota(parent, 0);
        vector<bool> res;
        for (auto &r : requests){
            int u = this->getPar(r[0], parent), v = this->getPar(r[1], parent);
            if (u > v){
                swap(u, v);
            }
            bool valid = true;
            for (auto &rr : restrictions){
                int a = this->getPar(rr[0], parent), b = this->getPar(rr[1], parent);
                if (a > b){
                    swap(a, b);
                }
                if (u == a && v == b){
                    valid = false;
                    break;
                }
            }
            res.push_back(valid);
            if (valid){
                this->unionGp(u, v, parent, size);
            }
        }
        return res;
    }
};
