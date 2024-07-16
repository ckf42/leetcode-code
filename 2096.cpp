struct Solution {
    bool dfs(TreeNode *node, int target, string &path){
        if (node == nullptr){
            return false;
        }
        if (node->val == target){
            return true;
        }
        path.push_back('L');
        if (this->dfs(node->left, target, path)){
            return true;
        }
        path.back() = 'R';
        if (this->dfs(node->right, target, path)){
            return true;
        } else {
            path.pop_back();
            return false;
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string p1, p2;
        this->dfs(root, startValue, p1);
        this->dfs(root, destValue, p2);
        int l1 = p1.size(), l2 = p2.size(), i = 0;
        while (i < min(l1, l2) && p1[i] == p2[i]){
            ++i;
        }
        string res(l1 - i, 'U');
        res += p2.substr(i);
        return res;
    }
};
