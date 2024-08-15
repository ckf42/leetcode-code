struct Solution {
    inline int numSteps(string &s) {
        int count = 0, j = s.size() - 1;
        int i = j;
        while (s[i] == '0'){
            --i;
        }
        count += j - i;
        j = i;
        while (j > 0){
            i = j - 1;
            while (i >= 0 && s[i] == '1'){
                --i;
            }
            count += j - i + 1;
            j = i;
        }
        return count;
    }
};
