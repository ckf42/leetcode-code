struct Solution {
    bool fill(int i, string &res, const string &pattern, array<bool, 9> &used){
        if (i >= res.size()){
            return true;
        }
        int inc = (pattern[i - 1] == 'I') ? 1 : -1;
        for (char c = res[i - 1]; c >= '1' && c <= '9'; c += inc){
            if (used[c - '1']){
                continue;
            }
            used[c - '1'] = true;
            res[i] = c;
            if (fill(i + 1, res, pattern, used)){
                return true;
            }
            used[c - '1'] = false;
        }
        return false;
    }
    string smallestNumber(string &pattern) {
        int n = pattern.size();
        string res(n + 1, '0');
        array<bool, 9> used;
        for (char c = 0; c < 9; ++c){
            res[0] = c + '1';
            used[c] = true;
            if (fill(1, res, pattern, used)){
                break;
            }
            used[c] = false;
        }
        return res;
    }
};
