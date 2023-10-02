struct Solution {
    string removeDuplicates(const string& s) {
        vector<char> st;
        for (const char c : s){
            if (st.empty() || st.back() != c){
                st.push_back(c);
            } else {
                st.pop_back();
            }
        }
        return string(st.cbegin(), st.cend());
    }
};
