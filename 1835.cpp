struct Solution {
    int getXORSum(const vector<int>& arr1, const vector<int>& arr2) const {
        int res1 = 0, res2 = 0;
        for (const int &n: arr1){
            res1 ^= n;
        }
        for (const int &n: arr2){
            res2 ^= n;
        }
        return res1 & res2;
    }
};
