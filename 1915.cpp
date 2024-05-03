struct Solution {
    inline long long wonderfulSubstrings(string &word) {
        int currMask = 0;
        unsigned long long knownMaskCount[1024];
        knownMaskCount[0] = 1;
        for (int i = 1; i < 1024; ++i){
            knownMaskCount[i] = 0;
        }
        for (char &c : word){
            currMask ^= (1 << (c - 'a'));
            ++knownMaskCount[currMask];
        }
        unsigned long long res = 0;
        for (int i = 0; i < 1024; ++i){
            res += knownMaskCount[i] * (knownMaskCount[i] - 1);
            for (int j = 0; j < 10; ++j){
                res += knownMaskCount[i] * knownMaskCount[i ^ (1 << j)];
            }
        }
        return res / 2;
    }
};
