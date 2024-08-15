struct Solution {
    bool isValid(string &s) {
        vector<char> st;
        for (char c : s){
            if (c == 'c' && st.size() >= 2 && st.back() == 'b' && st[st.size() - 2] == 'a'){
                st.pop_back();
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.size() == 0;
    }
};
