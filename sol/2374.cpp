struct Solution {
    int edgeScore(const vector<int>& edges) {
        vector<long long> scores(edges.size(), 0);
        for (size_t i = 0; i < edges.size(); ++i){
            scores[edges[i]] += i;
        }
        size_t idx = 0;
        for (size_t i = 1; i < edges.size(); ++i){
            if (scores[i] > scores[idx]){
                idx = i;
            }
        }
        return idx;
    }
};
