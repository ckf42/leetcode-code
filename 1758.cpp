struct Solution {
    int minOperations(const string &s) {
        size_t counter = 0;
        for (int i = 0; i < s.size(); ++i){
            if ((i ^ s[i]) & 1){
                ++counter;
            }
        }
        return min(counter, s.size() - counter);
    }
};
