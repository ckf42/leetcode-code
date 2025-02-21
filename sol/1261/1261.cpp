struct FindElements {
    TreeNode *m_root;
    FindElements(TreeNode* root):
        m_root(root) {}
    
    bool find(int target) {
        ++target;
        unsigned mask = 1;
        while (mask <= target){
            mask <<= 1;
        }
        mask >>= 2;
        TreeNode *ptr = m_root;
        while (ptr != nullptr && mask != 0){
            if (target & mask){
                ptr = ptr->right;
            } else {
                ptr = ptr->left;
            }
            mask >>= 1;
        }
        return ptr != nullptr;
    }
};

