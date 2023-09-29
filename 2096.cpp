struct Solution {
    inline bool getPath(const TreeNode* root, int target, string& path){
        if (root == nullptr){
            return false;
        }
        if (root->val == target){
            return true;
        }
        if (this->getPath(root->left, target, path)){
            path += "L";
            return true;
        }
        if (this->getPath(root->right, target, path)){
            path += "R";
            return true;
        }
        return false;
    }

    string getDirections(const TreeNode* root, int startValue, int destValue) {
        string startPath{""}, destPath{""};
        this->getPath(root, startValue, startPath);
        this->getPath(root, destValue, destPath);
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        size_t ptr = 0, minlen = min(startPath.size(), destPath.size());
        while (ptr < minlen && startPath[ptr] == destPath[ptr]){
            ++ptr;
        }
        return string(startPath.size() - ptr, 'U') + destPath.substr(ptr);
    }
};
