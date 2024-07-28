struct Solution {
    TreeNode *gen(int i, int j, vector<int>& nums){
        if (i >= j){
            return nullptr;
        }
        int m = (i + j) / 2;
        return new TreeNode(
                nums[m],
                this->gen(i, m, nums),
                this->gen(m + 1, j, nums)
        );
    }
    inline TreeNode* sortedArrayToBST(vector<int>& nums) {
        return this->gen(0, nums.size(), nums);
    }
};
