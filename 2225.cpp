#include <unordered_set>
#include <algorithm>

struct Solution {
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> noLose, oneLose, moreLose;
        for (vector<int> &m : matches){
            int w = m[0], l = m[1];
            if (!(oneLose.contains(w) || moreLose.contains(w))){
                noLose.insert(w);
            }
            if (noLose.contains(l)){
                noLose.erase(l);
                oneLose.insert(l);
            }  else if (oneLose.contains(l)){
                oneLose.erase(l);
                moreLose.insert(l);
            } else if (!moreLose.contains(l)){
                oneLose.insert(l);
            }
        }
        vector<vector<int>> answer(2);
        answer[0] = vector<int>(noLose.begin(), noLose.end());
        answer[1] = vector<int>(oneLose.begin(), oneLose.end());
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
