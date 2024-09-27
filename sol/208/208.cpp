struct Trie {
    struct TrieNode{
        int idx[26];
        bool exists;
        TrieNode(){
            for (char i = 0; i < 26; ++i){
                idx[i] = -1;
            }
            exists = false;
        }
    };
    vector<TrieNode> nodes;

    Trie(): nodes(1) {}
    
    void insert(const string &word) {
        int ptr = 0;
        for (char c : word){
            int &newPtr = this->nodes[ptr].idx[c - 'a'];
            if (newPtr == -1){
                ptr = newPtr = this->nodes.size();
                this->nodes.emplace_back();
            } else {
                ptr = newPtr;
            }
        }
        this->nodes[ptr].exists = true;
    }
    
    bool search(const string &word) {
        int ptr = 0;
        for (char c : word){
            ptr = this->nodes[ptr].idx[c - 'a'];
            if (ptr == -1){
                return false;
            }
        }
        return this->nodes[ptr].exists;
    }
    
    bool startsWith(const string &prefix) {
        int ptr = 0;
        for (char c : prefix){
            ptr = this->nodes[ptr].idx[c - 'a'];
            if (ptr == -1){
                return false;
            }
        }
        return true;
    }
};

