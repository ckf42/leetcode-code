#include <queue>
#include <unordered_set>

struct Solution {
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if (!wl.contains(endWord)){
            return 0;
        }
        int dep = 2;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()){
            int s = q.size();
            while (s-- > 0){
                string w = q.front();
                q.pop();
                for (int i = 0; i < w.size(); ++i){
                    char c = w[i];
                    for (int j = 0; j < 26; ++j){
                        w[i] = 'a' + j;
                        if (w == endWord){
                            return dep;
                        }
                        if (wl.contains(w)){
                            wl.erase(w);
                            q.push(w);
                        }
                    }
                    w[i] = c;
                }
            }
            ++dep;
        }
        return 0;
    }
};
