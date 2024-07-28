struct Solution {
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }
        vector<TreeNode*> nodest = {root};
        vector<char> visitst = {0};
        while (!nodest.empty()){
            TreeNode *node = nodest.back();
            nodest.pop_back();
            char visited = visitst.back();
            visitst.pop_back();
            if (node == nullptr){
                continue;
            }
            if (visited){
                res.push_back(node->val);
            } else {
                nodest.push_back(node);
                nodest.push_back(node->right);
                nodest.push_back(node->left);
                visitst.push_back(1);
                visitst.push_back(0);
                visitst.push_back(0);
            }
        }
        return res;
    }
};
