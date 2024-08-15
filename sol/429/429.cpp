struct Solution {
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        vector<Node*> lvl = {root}, newlvl;
        vector<int> buff;
        while (!lvl.empty()){
            buff.clear();
            newlvl.clear();
            for (Node *p : lvl){
                buff.push_back(p->val);
                for (Node *c : p->children){
                    if (c != nullptr){
                        newlvl.push_back(c);
                    }
                }
            }
            res.push_back(buff);
            swap(lvl, newlvl);
        }
        return res;
    }
};
