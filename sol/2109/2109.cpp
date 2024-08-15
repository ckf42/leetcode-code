struct Solution {
    string addSpaces(string &s, vector<int>& spaces) {
        string res;
        int prevIdx = 0;
        for (int idx : spaces){
            res += s.substr(prevIdx, idx - prevIdx) + ' ';
            prevIdx = idx;
        }
        res += s.substr(prevIdx);
        return res;
    }
};
