struct Solution {
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int sptr = 0, res = 0;
        for (int &gg : g){
            while (sptr < s.size() && s[sptr] < gg){
                ++sptr;
            }
            if (sptr == s.size()){
                break;
            }
            ++res;
            ++sptr;
        }
        return res;
    }
};
