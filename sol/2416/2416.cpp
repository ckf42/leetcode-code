struct Solution {
    struct TrieNode {
        int idx[26];
        int count;
        TrieNode(){
            for (int i = 0; i < 26; ++i){
                idx[i] = -1;
            }
            count = 0;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<TrieNode> nodes(1);
        int n = words.size();
        for (string &w : words){
            int ptr = 0;
            for (char c : w){
                int &newPtr = nodes[ptr].idx[c - 'a'];
                if (newPtr == -1){
                    newPtr = nodes.size();
                    nodes.emplace_back();
                }
                ptr = nodes[ptr].idx[c - 'a'];
                ++nodes[ptr].count;
            }
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i){
            int ptr = 0;
            for (char c : words[i]){
                ptr = nodes[ptr].idx[c - 'a'];
                res[i] += nodes[ptr].count;
            }
        }
        return res;
    }
};
