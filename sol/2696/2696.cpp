struct Solution {
    int minLength(string &s) {
        vector<char> st;
        for (char c : s){
            if (!st.empty() && ((st.back() == 'A' && c == 'B') || (st.back() == 'C' && c == 'D'))){
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.size();
    }
};
