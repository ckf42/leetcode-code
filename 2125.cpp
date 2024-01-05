struct Solution {
    int numberOfBeams(const vector<string>& bank) {
        int res = 0, prev = 0;
        for (const string &row : bank){
            int count = 0;
            for (const char &c : row){
                count += c == '1';
            }
            if (count != 0){
                res += prev * count;
                prev = count;
            }
        }
        return res;
    }
};
