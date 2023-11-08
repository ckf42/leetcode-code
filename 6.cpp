struct Solution {
    string convert(string s, int numRows) {
        string res = s;
        if (numRows == 1){
            return s;
        }
        int m = 2 * (numRows - 1), wptr = 0;
        for (int r = 0; r < numRows; ++r){
            for (int start = 0; start < s.size(); start += m){
                if (start + r < s.size()){
                    res[wptr++] = s[start + r];
                }
                if (r != 0 && r * 2 != m && start + m - r < s.size()){
                    res[wptr++] = s[start + m - r];
                }
            }
        }
        return res;
    }
};
