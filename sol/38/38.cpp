struct Solution {
    static array<string, 31> res;

    Solution() {
        res[1] = "1";  // idempotent
    }

    void compute(int n){
        string &res = Solution::res[n];
        const string &s = Solution::res[n - 1];
        if (res.size() != 0){
            return;
        }
        if (s.size() == 0){
            this->compute(n - 1);
        }
        char c = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); ++i){
            if (s[i] == c){
                ++count;
            } else {
                res += to_string(count);
                res += c;
                c = s[i];
                count = 1;
            }
        }
        res += to_string(count);
        res += c;
    }

    inline string countAndSay(int n) {
        if (Solution::res[n].size() == 0){
            this->compute(n);
        }
        return Solution::res[n];
    }
};

array<string, 31> Solution::res;
