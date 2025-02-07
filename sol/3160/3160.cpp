#include <unordered_map>

struct Solution {
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color, count;
        int n = queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i){
            int x = queries[i][0], newColor = queries[i][1];
            if (color.contains(x)){
                int oldColor = color[x];
                if (--count[oldColor] == 0){
                    count.erase(oldColor);
                }
            }
            ++count[newColor];
            color[x] = newColor;
            res[i] = count.size();
        }
        return res;
    }
};
