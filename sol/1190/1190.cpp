struct Solution {
    string reverseParentheses(string &s) {
        vector<string> st;
        st.push_back("");
        string buff{};
        for (char c : s){
            switch (c){
                case '(':
                    st.push_back("");
                    break;
                case ')':
                    buff = st.back();
                    st.pop_back();
                    reverse(buff.begin(), buff.end());
                    st.back() += buff;
                    break;
                default:
                    st.back().push_back(c);
                    break;
            }
        }
        return st.back();
    }
};
