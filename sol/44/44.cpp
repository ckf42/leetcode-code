struct Solution {
    bool isMatch(const string &s, const string &p) {
        vector<bool> hasMatch(s.size() + 1, false);
        hasMatch[s.size()] = true;
        for (int pi = p.size() - 1; pi >= 0; --pi){
            if (p[pi] == '*'){
                int firstIdx = s.size();
                while (firstIdx >= 0 && !hasMatch[firstIdx]){
                    --firstIdx;
                }
                if (firstIdx != -1){
                    for (int si = 0; si <= firstIdx; ++si){
                        hasMatch[si] = true;
                    }
                }
            } else {
                for (int si = 0; si < s.size(); ++si){
                    hasMatch[si] = (p[pi] == '?' || s[si] == p[pi]) && hasMatch[si + 1];
                }
            }
            if (hasMatch[s.size()]){
                hasMatch[s.size()] = p[pi] == '*';
            }
        }
        return hasMatch[0];
    }
};
