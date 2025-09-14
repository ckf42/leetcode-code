struct Solution {
    inline bool hasIntersection(const vector<int> &v1, const vector<int> &v2){
        auto it1 = v1.cbegin(), it2 = v2.cbegin();
        while ((it1 != v1.cend()) && (it2 != v2.cend())){
            if (*it1 == *it2){
                return true;
            } else if (*it1 < *it2){
                ++it1;
            } else {
                ++it2;
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        for (auto &v : languages){
            ranges::sort(v);
        }
        int m = languages.size(), total = 0;
        vector<bool> counted(m + 1, false);
        vector<int> userCount(n + 1, 0);
        for (auto &r : friendships){
            if (this->hasIntersection(languages[r[0] - 1], languages[r[1] - 1])){
                continue;
            }
            for (int x : r){
                if (!counted[x]){
                    counted[x] = true;
                    ++total;
                    for (int l : languages[x - 1]){
                        ++userCount[l];
                    }
                }
            }
        }
        return total - ranges::max(userCount);
    }
};
