struct Solution {
    string maximumOddBinaryNumber(string &s) {
        int n = s.size();
        int counter = 0;
        for (char c: s){
            counter += c == '1';
        }
        for (int i = 0; i < counter - 1; ++i){
            s[i] = '1';
        }
        for (int i = counter - 1; i < n - 1; ++i){
            s[i] = '0';
        }
        s[n - 1] = '1';
        return s;
    }
};
