struct Solution {
    void lot(TreeNode *node, vector<int> &arr){
        if (node->left != nullptr){
            lot(node->left, arr);
        }
        arr.push_back(node->val);
        if (node->right != nullptr){
            lot(node->right, arr);
        }
    }
    TreeNode* buildTree(int s, int e, const vector<int> &arr){
        if (e - s < 1){
            return nullptr;
        }
        int p = (s + e) / 2;
        return new TreeNode(arr[p], buildTree(s, p, arr), buildTree(p + 1, e, arr));
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        lot(root, arr);
        return buildTree(0, arr.size(), arr);
    }
};
