#include <unordered_map>

struct Solution {
    vector<int> restoreArray(const vector<vector<int>>& adjacentPairs) {
        unordered_multimap<int, int> edgeDict;
        for (const auto e : adjacentPairs){
            edgeDict.insert({e[0], e[1]});
            edgeDict.insert({e[1], e[0]});
        }
        int lastPtr, ptr, count;
        auto it = edgeDict.cbegin();
        while (it != edgeDict.cend()){
            count = edgeDict.count(it->first);
            if (count == 1){
                lastPtr = it->first;
                ptr = it->second;
                break;
            }
            while (count-- > 0){
                ++it;
            }
        }
        vector<int> res{lastPtr};
        while (res.size() != adjacentPairs.size() + 1){
            lastPtr = res.back();
            res.push_back(ptr);
            auto rg = edgeDict.equal_range(ptr);
            for (it = rg.first; it != rg.second; ++it){
                if (it->second != lastPtr){
                    ptr = it->second;
                    break;
                }
            }
        }
        return res;
    }
};
