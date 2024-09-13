struct Solution {
    int countConsistentStrings(string &allowed, vector<string>& words) {
        int m = 0;
        for (char c : allowed){
            m |= 1 << (c - 'a');
        }
        int res = words.size();
        for (string &w : words){
            for (char c : w){
                if (!(m & (1 << (c - 'a')))){
                    --res;
                    break;
                }
            }
        }
        return res;
    }
};
