struct Solution {
    bool rotateString(string &s, string &goal) {
        if (s.size() != goal.size()){
            return false;
        }
        return (s + s.substr(0, s.size() - 1)).find(goal) != string::npos;
    }
};
