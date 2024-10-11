struct Solution {
    int minSwaps(string &s) {
        int a = 0, b = 0;
        for (char c : s){
            if (c == '['){
                ++b;
            } else if (b == 0){
                ++a;
            } else {
                --b;
            }
        }
        return (a + 1) / 2;
    }
};
