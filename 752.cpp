#include <unordered_set>
#include <queue>

struct Solution {
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<int> visited;
        for (auto &st : deadends){
            visited.insert(std::stoi(st));
        }
        int targetInt = std::stoi(target);
        std::queue<int> states({0, -1});
        int counter = 0;
        bool lastIsEnded = true;
        while (!states.empty()){
            int st = states.front();
            states.pop();
            if (st < 0){
                if (lastIsEnded){
                    return -1;
                }
                lastIsEnded = true;
                ++counter;
                states.push(-1);
                continue;
            }
            lastIsEnded = false;
            if (st == targetInt){
                return counter;
            }
            if (visited.contains(st)){
                continue;
            }
            visited.insert(st);
            int refSt = st;
            for (int diff : {1, 10, 100, 1000}){
                int d = refSt % 10;
                states.push(d == 9 ? (st - 9 * diff) : (st + diff));
                states.push(d == 0 ? (st + 9 * diff) : (st - diff));
                refSt /= 10;
            }
        }
        return -1;
    }
};
