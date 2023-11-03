struct Solution {
    vector<string> buildArray(const vector<int>& target, int n) {
        int nextNum = 0;
        vector<string> res;
        for (int n : target){
            while (true){
                ++nextNum;
                res.push_back("Push");
                if (nextNum != n){
                    res.push_back("Pop");
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
