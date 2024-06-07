#include <unordered_map>
#include <ranges>

struct Solution {
    struct TrieNode {
        string cont;
        unordered_map<char, int> next;
    };

    string rep(string w, const vector<TrieNode> &trie){
        int ptr = 0;
        for (char &c : w){
            if (!trie[ptr].next.contains(c)){
                return w;
            }
            ptr = trie[ptr].next.at(c);
            if (trie[ptr].cont.size() != 0){
                return trie[ptr].cont;
            }
        }
        return w;
    }

    string replaceWords(vector<string>& dictionary, string &sentence) {
        vector<TrieNode> trie(1);
        for (string &w : dictionary){
            int ptr = 0;
            for (char &c : w){
                if (!trie[ptr].next.contains(c)){
                    trie[ptr].next[c] = trie.size();
                    trie.emplace_back();
                }
                ptr = trie[ptr].next[c];
            }
            trie[ptr].cont = w;
        }
        string res;
        int idx = 0;
        while (idx < sentence.size()){
            int nextIdx = sentence.find(' ', idx);
            if (nextIdx == string::npos){
                nextIdx = sentence.size();
            }
            res += this->rep(sentence.substr(idx, nextIdx - idx), trie) + " ";
            idx = nextIdx + 1;
        }
        res.pop_back();
        return res;
    }
};
