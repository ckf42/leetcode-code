struct Solution {
    int minimumRecolors(string &blocks, int k) {
        int n = blocks.size();
        int count = 0;
        for (int i = 0; i < k; ++i){
            count += blocks[i] == 'W';
        }
        int res = count;
        for (int i = k; i < n; ++i){
            count += (blocks[i] == 'W') - (blocks[i - k] == 'W');
            res = min(res, count);
        }
        return res;
    }
};
