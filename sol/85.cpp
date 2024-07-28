struct Solution {
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix.front().size(), res = 0, ptr;
        vector<int> proj(m, 0), st;
        for (auto &row : matrix){
            for (int j = 0; j < m; ++j){
                proj[j] = row[j] == '0' ? 0 : (proj[j] + 1);
            }
            st.clear();
            for (int x : proj){
                if (x == 0){
                    for (int i = 0; i < st.size(); ++i){
                        res = max(res, st[i] * static_cast<int>(st.size() - i));
                    }
                    st.clear();
                } else {
                    ptr = st.size() - 1;
                    while (ptr >= 0 && st[ptr] > x){
                        res = max(res, st[ptr] * static_cast<int>(st.size() - ptr));
                        st[ptr--] = x;
                    }
                    st.push_back(x);
                }
            }
            for (int i = 0; i < st.size(); ++i){
                res = max(res, st[i] * static_cast<int>(st.size() - i));
            }
        }
        return res;
    }
};
