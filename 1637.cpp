#include <set>

struct Solution {
    int maxWidthOfVerticalArea(const vector<vector<int>>& points) {
        set<int> xCoor;
        for (vector<vector<int>>::const_iterator it = points.cbegin();
             it != points.cend();
             ++it){
            xCoor.insert(*(it->cbegin()));
        }
        int prev = *xCoor.cbegin();
        int maxVal = 0;
        for (set<int>::const_iterator it = xCoor.cbegin();
             it != xCoor.cend();
             ++it){
            int diff = *it - prev;
            if (diff > maxVal){
                maxVal = diff;
            }
            prev = *it;
        }
        return maxVal;
    }
};
