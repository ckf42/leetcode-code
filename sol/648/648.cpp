struct Solution {
    struct TrieNode {
        int len = 0;
        int next[26] = {0};
    };

    string replaceWords(vector<string>& dictionary, string &sentence) {
        vector<TrieNode> trie(1);
        for (string &w : dictionary){
            int ptr = 0;
            for (char &c : w){
                if (trie[ptr].next[c - 'a'] == 0){
                    trie[ptr].next[c - 'a'] = trie.size();
                    trie.emplace_back();
                }
                ptr = trie[ptr].next[c - 'a'];
            }
            trie[ptr].len = w.size();
        }
        string res;
        int idx = 0;
        while (idx < sentence.size()){
            int nextIdx = sentence.find(' ', idx);
            if (nextIdx == string::npos){
                nextIdx = sentence.size();
            }
            int ptr = 0, repLen = nextIdx - idx;
            for (int i = idx; i < nextIdx; ++i){
                char &c = sentence[i];
                if (trie[ptr].next[c - 'a'] == 0){
                    break;
                }
                ptr = trie[ptr].next[c - 'a'];
                if (trie[ptr].len != 0){
                    repLen = trie[ptr].len;
                    break;
                }
            }
            res += sentence.substr(idx, repLen);
            res += " ";
            idx = nextIdx + 1;
        }
        res.pop_back();
        return res;
    }
};
