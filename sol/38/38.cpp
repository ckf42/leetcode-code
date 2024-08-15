struct Solution {
    static vector<string> res;

    Solution() {
        res[1] = "1";
    }

    void compute(int n){
        if (Solution::res[n].size() != 0){
            return;
        }
        if (Solution::res[n - 1].size() == 0){
            this->compute(n - 1);
        }
        string &s = Solution::res[n - 1];
        char c = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); ++i){
            if (s[i] == c){
                ++count;
            } else {
                Solution::res[n] += to_string(count);
                Solution::res[n] += c;
                c = s[i];
                count = 1;
            }
        }
        Solution::res[n] += to_string(count);
        Solution::res[n] += c;
    }

    inline string countAndSay(int n) {
        if (Solution::res[n].size() == 0){
            this->compute(n);
        }
        return Solution::res[n];
    }
};

vector<string> Solution::res(31);
