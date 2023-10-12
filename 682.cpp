#include <algorithm>

struct Solution {
    int calPoints(const vector<string>& operations) {
        vector<int> st;
        for (const string &op: operations){
            if (op == "+"){
                st.push_back(st.back() + *(st.rbegin() + 1));
            } else if (op == "D"){
                st.push_back(st.back() << 1);
            } else if (op == "C"){
                st.pop_back();
            } else {
                st.push_back(stoi(op));
            }
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};
