struct Solution {
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> badCount(n, 0);
        for (int i = 0; i < n - 1; ++i){
            badCount[i + 1] = badCount[i] + 1 - ((nums[i] ^ nums[i + 1]) & 1);
        }
        int q = queries.size();
        vector<bool> res(q, false);
        for (int i = 0; i < q; ++i){
            res[i] = badCount[queries[i][0]] == badCount[queries[i][1]];
        }
        return res;
    }
};
