struct Solution {
    inline int maximumGain(string &s, int x, int y) {
        int z = max(x, y), zz = min(x, y), res = 0, preCount = 0, postCount = 0;
        char preChar = x >= y ? 'a' : 'b';
        for (char &c : s){
            if (c != 'a' && c != 'b'){
                res += min(preCount, postCount) * zz;
                preCount = 0;
                postCount = 0;
            } else if (c == preChar){
                ++preCount;
            } else if (preCount != 0){
                --preCount;
                res += z;
            } else {
                ++postCount;
            }
        }
        return res + min(preCount, postCount) * zz;
    }
};
