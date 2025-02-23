struct Solution {
    TreeNode *recover(int &pres, int &posts, vector<int>& preorder, vector<int>& postorder){
        int v = preorder[pres++];
        TreeNode *newNode = new TreeNode(v);
        if (v != postorder[posts]){
            newNode->left = this->recover(pres, posts, preorder, postorder);
        }
        if (v != postorder[posts]){
            newNode->right = this->recover(pres, posts, preorder, postorder);
        }
        ++posts;
        return newNode;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pres = 0, posts = 0;
        return this->recover(pres, posts, preorder, postorder);
    }
};
