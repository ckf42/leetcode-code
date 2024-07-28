struct Solution {
    class TrieNode {
        public:
        int idx = -1;
        array<TrieNode *, 26> child = {nullptr};

        ~TrieNode() {
            for (auto &ptr : child) {
                if (ptr != nullptr){
                    delete ptr;
                }
            }
        }
    };

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        TrieNode root;
        for (int i = 0; i < wordDict.size(); ++i){
            TrieNode *ptr = &root;
            for (char &c : wordDict[i]){
                if (ptr->child[c - 'a'] == nullptr){
                    ptr->child[c - 'a'] = new TrieNode();
                }
                ptr = ptr->child[c - 'a'];
            }
            ptr->idx = i;
        }
        vector<vector<vector<int>>> memo(n);
        if (root.child[s[n - 1] - 'a'] != nullptr && root.child[s[n - 1] - 'a']->idx != -1){
            memo[n - 1].push_back({root.child[s[n - 1] - 'a']->idx});
        }
        for (int i = n - 2; i >= 0; --i){
            TrieNode *ptr = &root;
            bool isBroken = false;
            for (int j = i; j < n - 1; ++j){
                if (ptr->child[s[j] - 'a'] == nullptr){
                    isBroken = true;
                    break;
                }
                ptr = ptr->child[s[j] - 'a'];
                if (ptr->idx != -1){
                    int l = memo[i].size();
                    memo[i].reserve(l + memo[j + 1].size());
                    memo[i].insert(memo[i].end(), memo[j + 1].begin(), memo[j + 1].end());
                    for (int k = 0; k < memo[j + 1].size(); ++k){
                        memo[i][l + k].push_back(ptr->idx);
                    }
                }
            }
            if (!isBroken){
                ptr = ptr->child[s[n - 1] - 'a'];
                if (ptr != nullptr && ptr->idx != -1){
                    memo[i].push_back({ptr->idx});
                }
            }
        }
        vector<string> res;
        for (auto &p : memo[0]){
            int psize = p.size();
            string s = wordDict[p[psize - 1]];
            for (int i = p.size() - 2; i >= 0; --i){
                s += " ";
                s += wordDict[p[i]];
            }
            res.push_back(s);
        }
        return res;
    }
};
