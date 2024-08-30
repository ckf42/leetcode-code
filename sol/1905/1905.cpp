struct Solution {
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), res = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid2[i][j] == 0 || grid1[i][j] == 0){
                    continue;
                }
                vector<pair<int, int>> st;
                st.push_back({i, j});
                bool allCovered = true;
                while (!st.empty()){
                    auto [a, b] = st.back();
                    st.pop_back();
                    if (grid2[a][b] == 0){
                        continue;
                    }
                    grid2[a][b] = 0;
                    if (grid1[a][b] == 0){
                        allCovered = false;
                    }
                    if (a > 0 && grid2[a - 1][b]){
                        st.push_back({a - 1, b});
                    }
                    if (a < m - 1 && grid2[a + 1][b]){
                        st.push_back({a + 1, b});
                    }
                    if (b > 0 && grid2[a][b - 1]){
                        st.push_back({a, b - 1});
                    }
                    if (b < n - 1 && grid2[a][b + 1]){
                        st.push_back({a, b + 1});
                    }
                }
                res += allCovered;
            }
        }
        return res;
    }
};
