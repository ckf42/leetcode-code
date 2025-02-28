struct Solution {
    static constexpr int m = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int e = 0, o = 0, res = 0;
        for (int x : arr){
            ++e;
            if (x & 1){
                swap(e, o);
            }
            res = (res + o) % this->m;
        }
        return res;
    }
};
