struct Solution {
    bool canChange(string &start, string &target) {
        int l = 0, r = 0, n = start.size();
        for (int i = 0; i < n; ++i){
            if ((start[i] == 'L' && r != 0) || (target[i] == 'R' && l != 0)){
                return false;
            }
            l += (target[i] == 'L') - (start[i] == 'L');
            r -= (target[i] == 'R') - (start[i] == 'R');
            if (l < 0 || r < 0){
                return false;
            }
        }
        return l == 0 && r == 0;
    }
};
