struct Solution {
    static constexpr char tele[][8] = {
        "abc", "def","ghi",
        "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };
    void backtrack(int startIdx, string state, string &digits, vector<string> &res){
        if (startIdx == digits.size()){
            res.push_back(state);
            return;
        }
        for (char c : tele[digits[startIdx] - '2']){
            if (c == 0){
                break;
            }
            backtrack(startIdx + 1, state + c, digits, res);
        }
    }
    inline vector<string> letterCombinations(string &digits) {
        vector<string> res;
        if (digits.size() != 0){
            backtrack(0, "", digits, res);
        }
        return res;
    }
};
