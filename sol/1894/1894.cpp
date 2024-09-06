struct Solution {
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = 0;
        for (int c : chalk){
            total += c;
        }
        k %= total;
        for (int i = 0; i < chalk.size(); ++i){
            if (chalk[i] > k){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};
