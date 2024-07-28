struct Solution {
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.size() == 1){
            return strs.front();
        }
        size_t ptr = strs[0].size();
        for (int i = 1; i < strs.size(); ++i){
            ptr = min(ptr, strs[i].size());
            for (int j = 0; j < ptr; ++j){
                if (strs[0][j] != strs[i][j]){
                    ptr = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, ptr);
    }
};
