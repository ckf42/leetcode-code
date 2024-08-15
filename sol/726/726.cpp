#include <map>

struct Solution {
    using Counter = map<string, int>;

    inline static int toCount(string &str, int i, int j){
        int c = 0;
        while (i < j){
            c *= 10;
            c += str[i++] - '0';
        }
        return c;
    }

    string countOfAtoms(string &formula) {
        vector<Counter> st;
        st.emplace_back();
        int n = formula.size(), ptr = 0;
        while (ptr < n){
            if (formula[ptr] == '('){
                st.emplace_back();
                ++ptr;
            } else if (formula[ptr] == ')'){
                int s = ++ptr;
                while (ptr < n && formula[ptr] >= '0' && formula[ptr] <= '9'){
                    ++ptr;
                }
                int count = 1;
                if (ptr != s){
                    count = this->toCount(formula, s, ptr);
                }
                Counter m = st.back();
                st.pop_back();
                for (auto [k, v] : m){
                    st.back()[k] += v * count;
                }
            } else {
                int s = ptr++;
                while (ptr < n && formula[ptr] >= 'a'){
                    ++ptr;
                }
                int e = ptr;
                while (ptr < n && formula[ptr] >= '0' && formula[ptr] <= '9'){
                    ++ptr;
                }
                int count = 1;
                if (ptr != e){
                    count = this->toCount(formula, e, ptr);
                }
                st.back()[formula.substr(s, e - s)] += count;
            }
        }
        string res;
        for (auto [k, v] : st.back()){
            res += k;
            if (v != 1){
                res += to_string(v);
            }
        }
        return res;
    }
};
