struct Solution {
    void minStr(TreeNode *node, string &currSuff, string &currMin){
        currSuff += static_cast<char>(node->val + 'a');
        if (node->left == nullptr && node->right == nullptr){
            string copy(currSuff);
            reverse(copy.begin(), copy.end());
            currMin = min(currMin, copy);
        } else {
            if (node->left != nullptr){
                minStr(node->left, currSuff, currMin);
            }
            if (node->right != nullptr){
                minStr(node->right, currSuff, currMin);
            }
        }
        currSuff.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string currSuff = "", currMin = "{";
        minStr(root, currSuff, currMin);
        return currMin;
    }
};
