struct Solution {
    void pot(Node *node, vector<int> &res){
        if (node == nullptr){
            return;
        }
        for (auto child : node->children){
            this->pot(child, res);
        }
        res.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        this->pot(root, res);
        return res;
    }
};
