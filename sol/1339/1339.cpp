struct Solution {
    static constexpr unsigned long m = 1000000007;
    vector<unsigned long> subsum; // surprisingly using forward_list yield error on first testcase

    unsigned long calSubSum(const TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        unsigned long v = root->val + this->calSubSum(root->left) + this->calSubSum(root->right);
        this->subsum.push_back(v);
        return v;
    }

    int maxProduct(const TreeNode* root) {
        unsigned long totalSum = this->calSubSum(root);
        unsigned long halfSum = totalSum / 2, closestVal, closestDist, dist, v;
        bool flag = false;
        for (vector<unsigned long>::const_iterator it = this->subsum.cbegin();
             it != this->subsum.cend();
             ++it){
            v = *it;
            dist = (v >= halfSum) ? (v - halfSum) : (halfSum - v);
            if (!flag || dist < closestDist){
                flag = true;
                closestDist = dist;
                closestVal = v % this->m;
            }
        }
        return (closestVal * ((totalSum % this->m) - closestVal)) % this->m;
    }
};
