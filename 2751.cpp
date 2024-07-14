struct Solution {
    struct Robot {
        int idx;
        int health;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&positions](int i, int j){return positions[i] < positions[j];});
        vector<Robot> res, st;
        for (int i : indices){
            if (directions[i] == 'R'){
                st.emplace_back(i, healths[i]);
            } else {
                int h = healths[i];
                while (!st.empty()){
                    if (h <= st.back().health){
                        if (h == st.back().health){
                            st.pop_back();
                        } else {
                            --st.back().health;
                        }
                        h = -1;
                        break;
                    } else {
                        st.pop_back();
                        --h;
                    }
                }
                if (h != -1){
                    res.emplace_back(i, h);
                }
            }
        }
        res.insert(res.end(), st.begin(), st.end());
        sort(res.begin(), res.end(), [](const Robot &a, const Robot &b){return a.idx < b.idx;});
        vector<int> remainHealth(res.size());
        int w = 0;
        for (Robot &r : res){
            remainHealth[w++] = r.health;
        }
        return remainHealth;
    }
};
