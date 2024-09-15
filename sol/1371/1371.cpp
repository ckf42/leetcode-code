struct Solution {
    int findTheLongestSubstring(string &s) {
        int idx[32];
        idx[0] = -1;
        for (int i = 1; i < 32; ++i){
            idx[i] = -2;
        }
        int mask = 0, res = 0;
        for (int i = 0; i < s.size(); ++i){
            switch (s[i]){
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }
            if (idx[mask] == -2){
                idx[mask] = i;
            } else {
                res = max(res, i - idx[mask]);
            }
        }
        return res;
    }
};
