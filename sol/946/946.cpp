#include <stack>

struct Solution {
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> st;
        size_t pushPtr = 0, popPtr = 0, pushSize = pushed.size(), popSize = popped.size();
        while (true){
            while (popPtr < popSize && !st.empty() && popped[popPtr] == st.top()){
                st.pop();
                ++popPtr;
            }
            if (popPtr == popSize){
                return true;
            }
            if (pushPtr < pushSize){
                st.push(pushed[pushPtr++]);
            } else {
                return false;
            }
        }
    }
};
