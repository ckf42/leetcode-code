struct Solution {
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int l = 0, r = n - 1, res = 0, score = 0;
        while (l <= r){
            while (l < n && power >= tokens[l]){
                power -= tokens[l++];
                ++score;
            }
            res = max(res, score);
            if (score == 0){
                break;
            }
            power += tokens[r--];
            --score;
        }
        return res;
    }
};
