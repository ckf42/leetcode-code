struct Solution {
    struct Proj {
        int profit;
        int capital;

        friend bool operator<(const Proj &a, const Proj &b) {
            return a.profit < b.profit;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), ptr = 0;
        vector<Proj> projs(n), h;
        for (int i = 0; i < n; ++i){
            projs[i] = Proj(profits[i], capital[i]);
        }
        sort(projs.begin(), projs.end(), [](const Proj &a, const Proj &b){return a.capital < b.capital;});
        while (k-- > 0){
            while (ptr < n && projs[ptr].capital <= w){
                h.push_back(projs[ptr++]);
                push_heap(h.begin(), h.end());
            }
            if (h.empty()){
                break;
            }
            pop_heap(h.begin(), h.end());
            w += h.back().profit;
            h.pop_back();
        }
        return w;
    }
};
