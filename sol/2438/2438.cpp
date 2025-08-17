struct Solution {
    static vector<int> TABLE;
    static constexpr int m = 1e9 + 7;

    Solution(){
        if (this->TABLE.empty()){
            this->TABLE.push_back(1);
            for (int i = 1; i <= 435; ++i){
                this->TABLE.push_back((this->TABLE.back() * 2) % this->m);
            }
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> indices(1, 0);
        int mask = 1, idx = 0;
        while (mask <= n){
            if (mask & n){
                indices.push_back(idx);
            }
            ++idx;
            mask <<= 1;
        }
        int l = indices.size();
        for (int i = 1; i < l; ++i){
            indices[i] += indices[i - 1];
        }
        vector<int> res;
        for (auto &q : queries){
            res.push_back(this->TABLE[indices[q[1] + 1] - indices[q[0]]]);
        }
        return res;
    }
};
vector<int> Solution::TABLE = vector<int>();
