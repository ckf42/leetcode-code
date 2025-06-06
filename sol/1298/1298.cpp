#include <queue>

struct Solution {
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<bool> unopenedBox(n, false), unusedKey(n, false), opened(n, false);
        for (int b : initialBoxes){
            if (status[b]){
                q.push(b);
            } else {
                unopenedBox[b] = true;
            }
        }
        int total = 0;
        while (!q.empty()){
            int b = q.front();
            q.pop();
            if (opened[b]){
                continue;
            }
            opened[b] = true;
            unopenedBox[b] = false;
            total += candies[b];
            for (int nb : keys[b]){
                if (unopenedBox[nb]){
                    q.push(nb);
                } else {
                    unusedKey[nb] = true;
                }
            }
            for (int nb : containedBoxes[b]){
                if (status[nb] || unusedKey[nb]){
                    q.push(nb);
                } else {
                    unopenedBox[nb] = true;
                }
            }
        }
        return total;
    }
};
