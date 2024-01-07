#include <unordered_set>

struct Solution {
    constexpr static int N = 10000;
    bool isPathCrossing(const string &path) {
        int coor = 0;
        unordered_set<int> visited({0});
        for (char c: path){
            switch (c){
                case 'N':
                    ++coor;
                    break;
                case 'S':
                    --coor;
                    break;
                case 'E':
                    coor += N;
                    break;
                case 'W':
                    coor -= N;
                    break;
            }
            cout << coor << endl;
            if (visited.contains(coor)){
                return true;
            }
            visited.insert(coor);
        }
        return false;
    }
};
