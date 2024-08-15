struct Solution {
    inline int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i){
            res += (heights[i] != expected[i]);
        }
        return res;
    }
};
