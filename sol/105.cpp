#include <unordered_map>
struct Solution {
    TreeNode *gen(
            int pi, int pj, int ii, int ij, 
            vector<int>& preorder, vector<int>& inorder,
            unordered_map<int, int> &h){
        if (pi >= pj){
            return nullptr;
        }
        int val = preorder[pi];
        int l = h[val] - ii;
        return new TreeNode(
                val,
                this->gen(pi + 1, pi + l + 1, ii, ii + l, preorder, inorder, h),
                this->gen(pi + l + 1, pj, ii + l + 1, ij, preorder, inorder, h)
        );
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> h;
        for (int i = 0; i < n; ++i){
            h[inorder[i]] = i;
        }
        return this->gen(0, n, 0, n, preorder, inorder, h);
    }
};
