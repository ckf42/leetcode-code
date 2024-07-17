struct Solution {
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y){
            return false;
        }
        vector<TreeNode*> nodeSt, parSt;
        nodeSt.push_back(root); parSt.push_back(nullptr);
        vector<int> depSt;
        depSt.push_back(0);
        int dx = -1, dy = -1;
        TreeNode *parx = nullptr, *pary = nullptr;
        while (!nodeSt.empty()){
            TreeNode *node = nodeSt.back(), *par = parSt.back();
            nodeSt.pop_back(); parSt.pop_back();
            int dep = depSt.back();
            depSt.pop_back();
            if (node->val == x){
                dx = dep;
                parx = par;
            } else if (node->val == y){
                dy = dep;
                pary = par;
            }
            if (dx != -1 && dy != -1){
                return dx == dy && parx != pary;
            }
            if (node->left != nullptr){
                nodeSt.push_back(node->left);
                parSt.push_back(node);
                depSt.push_back(dep + 1);
            }
            if (node->right != nullptr){
                nodeSt.push_back(node->right);
                parSt.push_back(node);
                depSt.push_back(dep + 1);
            }
        }
        return false;
    }
};
