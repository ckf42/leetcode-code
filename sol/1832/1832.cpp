struct Solution {
    inline bool checkIfPangram(string &sentence) {
        int flag = 0;
        short count = 0;
        for (char c : sentence){
            int m = 1 << (c - 'a');
            if ((flag & m) == 0){
                ++count;
                flag |= m;
            }
        }
        return count == 26;
    }
};
