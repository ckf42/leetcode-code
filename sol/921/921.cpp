struct Solution {
    int minAddToMakeValid(string &s) {
        int a = 0, b = 0;
        for (char c : s){
            if (c == '('){
                ++b;
            } else if (b != 0){
                --b;
            } else {
                ++a;
            }
        }
        return a + b;
    }
};
