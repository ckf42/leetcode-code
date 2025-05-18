struct Solution {
    static constexpr int M = 1e9 + 7;
    void genCol(int prev, int remainLen, vector<int> &state, vector<vector<int>> &out){
        if (remainLen == 0){
            out.push_back(state);
            return;
        }
        for (int i : {0, 1, 2}){
            if (i == prev){
                continue;
            }
            state.push_back(i);
            this->genCol(i, remainLen - 1, state, out);
            state.pop_back();
        }
    }
    int colorTheGrid(int m, int n) {
        vector<vector<int>> allCols;
        vector<int> state;
        this->genCol(-1, m, state, allCols);
        int l = allCols.size();
        vector<vector<int>> adj(l);
        for (int i = 0; i < l; ++i){
            for (int j = i + 1; j < l; ++j){
                bool canAdj = true;
                for (int idx = 0; idx < m; ++idx){
                    if (allCols[i][idx] == allCols[j][idx]){
                        canAdj = false;
                        break;
                    }
                }
                if (canAdj){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> buff[2];
        buff[0] = vector<int>(l, 1);
        buff[1].resize(l);
        int ptr = 0;
        for (int idx = 2; idx <= n; ++idx){
            buff[ptr ^ 1].assign(l, 0);
            for (int i = 0; i < l; ++i){
                for (int j : adj[i]){
                    buff[ptr ^ 1][i] = (buff[ptr ^ 1][i] + buff[ptr][j]) % this->M;
                }
            }
            ptr ^= 1;
        }
        int res = 0;
        for (int x : buff[ptr]){
            res = (res + x) % this->M;
        }
        return res;
    }
};
