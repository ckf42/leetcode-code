struct Solution {
    using ll = long long;
    long long minimumCost(
            string &source, string &target, 
            vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll dist[26][26];
        for (int i = 0; i < 26; ++i){
            for (int j = 0; j < 26; ++j){
                dist[i][j] = ((i == j) ? 0 : 1e9);
            }
        }
        for (int i = 0; i < cost.size(); ++i){
            ll &w = dist[original[i] - 'a'][changed[i] - 'a'];
            w = min(w, static_cast<ll>(cost[i]));
        }
        for (int k = 0; k < 26; ++k){
            for (int i = 0; i < 26; ++i){
                for (int j = 0; j < 26; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < source.size(); ++i){
            ll w = dist[source[i] - 'a'][target[i] - 'a'];
            if (w == 1e9){
                return -1;
            }
            res += w;
        }
        return res;
    }
};
