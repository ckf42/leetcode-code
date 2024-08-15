struct Solution {
    void mark(int i, int j, int k, int coor, const vector<string> &grid, vector<bool> &visited){
        if (visited[coor]){
            return;
        }
        visited[coor] = true;
        if (grid[i][j] != '/'){
            this->mark(i, j, 3 - k, coor - k * 2 + 3, grid, visited);
        }
        if (grid[i][j] != '\\'){
            this->mark(i, j, k ^ 1, coor ^ 1, grid, visited);
        }
        switch (k){
            case 0:
                if (j != grid.size() - 1){
                    this->mark(i, j + 1, 2, coor + 6, grid, visited);
                }
                break;
            case 1:
                if (i != grid.size() - 1){
                    this->mark(i + 1, j, 3, coor + grid.size() * 4 + 2, grid, visited);
                }
                break;
            case 2:
                if (j != 0){
                    this->mark(i, j - 1, 0, coor - 6, grid, visited);
                }
                break;
            case 3:
                if (i != 0){
                    this->mark(i - 1, j, 1, coor - grid.size() * 4 - 2, grid, visited);
                }
                break;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<bool> visited(n * n * 4, false);
        int res = 0, coor = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < 4; ++k){
                    if (!visited[coor]){
                        ++res;
                        this->mark(i, j, k, coor, grid, visited);
                    }
                    ++coor;
                }
            }
        }
        return res;
    }
};
