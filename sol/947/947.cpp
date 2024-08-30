struct Solution {
    int getPar(int idx, vector<int> &parent){
        while (parent[idx] != idx){
            int temp = idx;
            idx = parent[temp];
            parent[temp] = parent[parent[temp]];
        }
        return idx;
    }
    void unionGp(int i, int j, vector<int> &parent, vector<int> &size){
        i = this->getPar(i, parent);
        j = this->getPar(j, parent);
        if (i == j){
            return;
        }
        if (size[i] < size[j]){
            swap(i, j);
        }
        parent[j] = i;
        size[i] += size[j];
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), maxRows = 0, maxCols = 0;
        for (auto &p : stones){
            maxRows = max(maxRows, p[0]);
            maxCols = max(maxCols, p[1]);
        }
        int m = maxRows + maxCols + 2;
        vector<int> parent(m), size(m, 0);
        ranges::iota(parent, 0);
        for (auto &p : stones){
            ++size[p[0]];
            ++size[maxRows + 1 + p[1]];
        }
        for (auto &p : stones){
            this->unionGp(p[0], maxRows + 1 + p[1], parent, size);
        }
        int res = 0;
        for (int i = 0; i < m; ++i){
            int p = this->getPar(i, parent);
            if (size[p] != 0){
                res += size[p] / 2 - 1;
                size[p] = 0;
            }
        }
        return res;
    }
};
