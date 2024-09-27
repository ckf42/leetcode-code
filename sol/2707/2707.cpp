struct Solution {
    struct TrieNode {
        int idx[26];
        bool isLeaf;
        TrieNode(void){
            for (int i = 0; i < 26; ++i){
                idx[i] = -1;
            }
            isLeaf = false;
        }
    };
    int minExtraChar(string &s, vector<string>& dictionary) {
        vector<TrieNode> nodes(1);
        int root = 0;
        for (auto &w : dictionary){
            int ptr = root;
            for (char c : w){
                if (nodes[ptr].idx[c - 'a'] == -1){
                    nodes[ptr].idx[c - 'a'] = nodes.size();
                    nodes.emplace_back();
                }
                ptr = nodes[ptr].idx[c - 'a'];
            }
            nodes[ptr].isLeaf = true;
        }
        int n = s.size();
        vector<int> memo(n + 1, 0);
        for (int i = n - 1; i >= 0; --i){
            int val = memo[i + 1] + 1;
            int ptr = root;
            for (int j = i; j < n; ++j){
                if (nodes[ptr].idx[s[j] - 'a'] == -1){
                    break;
                }
                ptr = nodes[ptr].idx[s[j] - 'a'];
                if (nodes[ptr].isLeaf){
                    val = min(val, memo[j + 1]);
                }
            }
            memo[i] = val;
        }
        return memo[0];
    }
};
