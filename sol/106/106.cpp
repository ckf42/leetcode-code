#include <unordered_map>

struct Solution {
    TreeNode *gen(
            int ii, int ij, int pi, int pj,
            vector<int>& inorder, vector<int>& postorder,
            unordered_map<int, int> &h) {
        if (ii >= ij){
            return nullptr;
        }
        int val = postorder[pj - 1];
        int l = h[val] - ii;
        return new TreeNode(
                val,
                this->gen(ii, ii + l, pi, pi + l, inorder, postorder, h),
                this->gen(ii + l + 1, ij, pi + l, pj - 1, inorder, postorder, h)
        );
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> h;
        int n = inorder.size();
        for (int i = 0; i < n; ++i){
            h[inorder[i]] = i;
        }
        return this->gen(0, n, 0, n, inorder, postorder, h);
    }
};
