struct Solution {
    int getParent(int idx, vector<int> &parents){
        while (parents[idx] != idx){
            int temp = parents[idx];
            parents[idx] = parents[temp];
            idx = temp;
        }
        return idx;
    }
    void unionGp(int x, int y, vector<int> &parents, vector<int> &sizes){
        x = this->getParent(x, parents);
        y = this->getParent(y, parents);
        if (x == y){
            return;
        }
        if (sizes[x] < sizes[y]){
            swap(x, y);
        }
        parents[y] = x;
        sizes[x] += sizes[y];
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<int> parents(m + n), sizes(m + n, 1);
        ranges::iota(parents, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    ++count;
                    this->unionGp(i, j + m, parents, sizes);
                }
            }
        }
        for (int i = 0; i < m; ++i){
            if (sizes[this->getParent(i, parents)] == 2){
                --count;
            }
        }
        return count;
    }
};
