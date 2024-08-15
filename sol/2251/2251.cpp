#include <algorithm>

struct Solution {
    vector<int> fullBloomFlowers(const vector<vector<int>>& flowers, const vector<int>& people) {
        vector<int> res(people.size(), 0);
        vector<int> startTimes(flowers.size(), 0), endTimes(flowers.size(), 0);
        for (size_t i = 0; i < flowers.size(); ++i){
            startTimes[i] = flowers[i][0];
            endTimes[i] = flowers[i][1];
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        for (size_t i = 0; i < people.size(); ++i){
            res[i] = (upper_bound(startTimes.cbegin(), startTimes.cend(), people[i]) - startTimes.cbegin()) 
                - (lower_bound(endTimes.cbegin(), endTimes.cend(), people[i]) - endTimes.cbegin());
        }
        return res;
    }
};
