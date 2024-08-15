struct Solution {
    inline int getLastMoment(int n, const vector<int>& left, const vector<int>& right) {
        int res = 0;
        for (int c: left){
            res = max(res, c);
        }
        for (int c: right){
            res = max(res, n - c);
        }
        return res;
    }
};
