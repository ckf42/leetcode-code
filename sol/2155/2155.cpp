struct Solution {
    inline vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res(1, 0);
        int score = 0, high = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                ++score;
            } else {
                --score;
            }
            if (score > high){
                high = score;
                res.clear();
            }
            if (score == high){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
