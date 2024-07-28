#include <queue>

struct Solution {
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        queue<int> q;
        for (int i = 0; i < deck.size(); ++i){
            q.push(i);
        }
        int idx = 0;
        while (!q.empty()){
            res[q.front()] = deck[idx++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};
