struct Solution {
    string simplifyPath(string &path) {
        vector<string> st;
        int i = 1;
        while (i < path.size()){
            int j = i;
            while (j < path.size() && path[j] != '/'){
                ++j;
            }
            string comp = path.substr(i, j - i);
            if (comp == ".."){
                if (!st.empty()){
                    st.pop_back();
                }
            } else if (comp.size() != 0 && comp != "."){
                st.push_back(comp);
            }
            i = j + 1;
        }
        if (st.size() == 0){
            return "/";
        }
        string res = "";
        for (string &comp : st){
            res += "/" + comp;
        }
        return res;

    }
};
