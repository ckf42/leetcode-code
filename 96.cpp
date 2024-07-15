struct Solution {
    static vector<int> rec;
    int numTrees(int n) {
        int k, res;
        while (n >= (k = this->rec.size())){
            res = 0;
            for (int i = 0; i < k / 2; ++i){
                res += this->rec[i] * this->rec[k - 1 - i];
            }
            res <<= 1;
            if ((k & 1) == 1){
                res += this->rec[(k - 1) / 2] * this->rec[(k - 1) / 2];
            }
            this->rec.push_back(res);
        }
        return this->rec[n];
    }
};

vector<int> Solution::rec = {1, 1};
