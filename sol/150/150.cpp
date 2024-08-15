struct Solution {
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1, op2;
        for (string &s : tokens){
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                switch (s[0]){
                    case '+':
                        st.push(op1 + op2);
                        break;
                    case '-':
                        st.push(op1 - op2);
                        break;
                    case '*':
                        st.push(op1 * op2);
                        break;
                    case '/':
                        st.push(op1 / op2);
                        break;
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
