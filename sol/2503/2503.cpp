struct Solution {
    static constexpr int THRESHOLD = 1e7;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), q = queries.size();
        vector<int> sortedIdx(q);
        ranges::iota(sortedIdx, 0);
        ranges::sort(sortedIdx, [&](int a, int b){return queries[a] < queries[b];});
        vector<pair<int, pair<int, int>>> terminals;
        terminals.push_back({-grid[0][0], {0, 0}});
        grid[0][0] = this->THRESHOLD;
        vector<int> res(q);
        int count = 0;
        for (int idx : sortedIdx){
            int query = queries[idx];
            vector<pair<int, int>> buff;
            while (!terminals.empty() && -terminals[0].first < query){
                buff.push_back(terminals[0].second);
                ranges::pop_heap(terminals);
                terminals.pop_back();
            }
            while (!buff.empty()){
                auto [x, y] = buff.back();
                buff.pop_back();
                ++count;
                if (x > 0 && grid[x - 1][y] != this->THRESHOLD){
                    if (grid[x - 1][y] < query){
                        buff.push_back({x - 1, y});
                    } else {
                        terminals.push_back({-grid[x - 1][y], {x - 1, y}});
                        ranges::push_heap(terminals);
                    }
                    grid[x - 1][y] = this->THRESHOLD;
                }
                if (x < m - 1 && grid[x + 1][y] != this->THRESHOLD){
                    if (grid[x + 1][y] < query){
                        buff.push_back({x + 1, y});
                    } else {
                        terminals.push_back({-grid[x + 1][y], {x + 1, y}});
                        ranges::push_heap(terminals);
                    }
                    grid[x + 1][y] = this->THRESHOLD;
                }
                if (y > 0 && grid[x][y - 1] != this->THRESHOLD){
                    if (grid[x][y - 1] < query){
                        buff.push_back({x, y - 1});
                    } else {
                        terminals.push_back({-grid[x][y - 1], {x, y - 1}});
                        ranges::push_heap(terminals);
                    }
                    grid[x][y - 1] = this->THRESHOLD;
                }
                if (y < n - 1 && grid[x][y + 1] != this->THRESHOLD){
                    if (grid[x][y + 1] < query){
                        buff.push_back({x, y + 1});
                    } else {
                        terminals.push_back({-grid[x][y + 1], {x, y + 1}});
                        ranges::push_heap(terminals);
                    }
                    grid[x][y + 1] = this->THRESHOLD;
                }
            }
            res[idx] = count;
        }
        return res;
    }
};
