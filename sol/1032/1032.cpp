#include <deque>

struct StreamChecker {
    struct TrieNode {
        int next[26];
        bool contains;

        TrieNode(): contains(false) {
            for (int i = 0; i < 26; ++i){
                this->next[i] = -1;
            }
        }

    };

    vector<TrieNode> nodes;
    deque<int> qptrs;

    StreamChecker(vector<string>& words): nodes(1), qptrs() {
        for (auto &w : words){
            int ptr = 0;
            for (char c : w){
                c -= 'a';
                if (this->nodes[ptr].next[c] == -1){
                    this->nodes[ptr].next[c] = this->nodes.size();
                    this->nodes.emplace_back();
                }
                ptr = this->nodes[ptr].next[c];
            }
            this->nodes[ptr].contains = true;
        }
    }
    
    bool query(char letter) {
        letter -= 'a';
        this->qptrs.push_back(0);
        this->qptrs.push_back(-1);
        bool seen = false;
        while (true){
            int ptr = this->qptrs.front();
            this->qptrs.pop_front();
            if (ptr == -1){
                break;
            }
            int nextPtr = this->nodes[ptr].next[letter];
            if (nextPtr != -1){
                ptr = nextPtr;
                seen |= this->nodes[ptr].contains;
                this->qptrs.push_back(ptr);
            }
        }
        return seen;

    }
};

