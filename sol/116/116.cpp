struct Solution {
    void make(Node *node){
        if (node->left == nullptr){
            return;
        }
        node->left->next = node->right;
        if (node->next != nullptr){
            node->right->next = node->next->left;
        }
        this->make(node->left);
        this->make(node->right);
    }
    inline Node* connect(Node* root) {
        if (root == nullptr){
            return nullptr;
        }
        this->make(root);
        return root;
    }
};
