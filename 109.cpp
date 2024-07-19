struct Solution {
    TreeNode *gen(int n, ListNode * & node){
        if (node == nullptr || n == 0){
            return nullptr;
        }
        if (n == 1){
            TreeNode *t = new TreeNode(node->val);
            node = node->next;
            return t;
        }
        TreeNode *ln = this->gen(n / 2, node);
        TreeNode *t = new TreeNode(node->val, ln, nullptr);
        node = node->next;
        t->right = this->gen(n - n / 2 - 1, node);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode *ptr = head;
        int n = 0;
        while (ptr != nullptr){
            ++n;
            ptr = ptr->next;
        }
        return this->gen(n, head);
    }
};
