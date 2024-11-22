#include <unordered_map>

struct Solution {
    using vb = vector<bool>;
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), res = 0;
        vb buff(m);
        unordered_map<vb, int> d;
        for (auto &r : matrix){
            if (r[0] == 0){
                res = max(res, ++d[vb(r.begin(), r.end())]);
            } else {
                for (int i = 0; i < m; ++i){
                    buff[i] = r[i] ^ 1;
                }
                res = max(res, ++d[buff]);
            }
        }
        return res;
    }
};
