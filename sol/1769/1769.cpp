struct Solution {
    vector<int> minOperations(string &boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i){
            if (boxes[i] == '1'){
                ++r;
                res[0] += i;
            }
        }
        for (int i = 1; i < n; ++i){
            l += boxes[i - 1] == '1';
            res[i] = res[i - 1] + l - r;
            r -= boxes[i] == '1';
        }
        return res;
    }
};
