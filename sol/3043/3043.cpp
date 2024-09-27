struct Solution {
    struct TrieNode {
        int idx[10];
        TrieNode(){
            for (int i = 0; i < 10; ++i){
                idx[i] = -1;
            }
        }
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<TrieNode> nodes(1);
        for (int x : arr1){
            string xs = to_string(x);
            int ptr = 0;
            for (char c : xs){
                int &newPtr = nodes[ptr].idx[c - '0'];
                if (newPtr == -1){
                    newPtr = nodes.size();
                    nodes.emplace_back();
                }
                ptr = nodes[ptr].idx[c - '0'];
            }
        }
        int res = 0;
        for (int x : arr2){
            string xs = to_string(x);
            int ptr = 0, dep = 0;
            for (char c : xs){
                int &newPtr = nodes[ptr].idx[c - '0'];
                if (newPtr == -1){
                    break;
                }
                ptr = newPtr;
                ++dep;
            }
            res = max(res, dep);
        }
        return res;
    }
};
