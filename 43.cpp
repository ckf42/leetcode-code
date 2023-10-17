struct Solution {
    string multiply(const string &num1, const string &num2) {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        int d, idx = 0, lab = num1.size() + num2.size();
        vector<short> mem(lab, 0);
        for (int i = num2.size() - 1; i >= 0; --i){
            d = num2[i] - '0';
            for (int j = num1.size() - 1; j >= 0; --j){
                mem[i + j + 1] += d * (num1[j] - '0');
                mem[i + j] += mem[i + j + 1] / 10;
                mem[i + j + 1] %= 10;
            }
        }
        if (mem[1] >= 10){
            mem[0] += mem[1] / 10;
            mem[1] %= 10;
        }
        while (idx < lab && mem[idx] == 0){
            ++idx;
        }
        return accumulate(mem.cbegin() + idx, mem.cend(), string(), [](string a, int b){return a + to_string(b);});
    }
};
