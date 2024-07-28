struct Solution {
    static constexpr int mask = 0x4c02;
    static inline int getIdx(char c){
        return (mask >> (c - 'a')) & 3;
    }
    int minNumberOfFrogs(string &croakOfFrogs) {
        int freq[5] = {0}, res = 0, count = 0;
        for (char c : croakOfFrogs){
            if (c == 'c'){
                ++freq[0];
                res = max(res, ++count);
            } else {
                int idx = getIdx(c);
                if (freq[idx] == 0){
                    return -1;
                }
                --freq[idx];
                if (c != 'k'){
                    ++freq[idx + 1];
                } else {
                    --count;
                }
            }
        }
        if ((freq[0] | freq[1] | freq[2] | freq[3] | freq[4]) != 0){
            return -1;
        }
        return res;
    }
};
