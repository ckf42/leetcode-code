struct Solution {
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *created[100001] = {nullptr};
        int parent[100001] = {0};
        int rootval = -1;
        for (auto &rec : descriptions){
            parent[rec[1]] = rec[0];
            if (created[rec[0]] == nullptr){
                created[rec[0]] = new TreeNode(rec[0]);
            }
            if (created[rec[1]] == nullptr){
                created[rec[1]] = new TreeNode(rec[1]);
            }
            rootval = rec[0];
            if (rec[2]){
                created[rec[0]]->left = created[rec[1]];
            }  else {
                created[rec[0]]->right = created[rec[1]];
            }
        }
        while (parent[rootval] != 0){
            rootval = parent[rootval];
        }
        return created[rootval];
    }
};
