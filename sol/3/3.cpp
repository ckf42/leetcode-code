struct Solution {
    int lengthOfLongestSubstring(string &s) {
        if (s.size() <= 1){
            return s.size();
        }
        int count[128] = {0}, res = 1, i = 0;
        for (int j = 0; j < s.size(); ++j){
            char &c = s[j];
            ++count[c];
            while (count[c] > 1){
                --count[s[i++]];
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
