struct Solution {
    inline int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), curr = 0, mingas = 2147483647, mingasidx = 0;
        for (int i = 0; i < n; ++i){
            curr += gas[i] - cost[i];
            if (curr <= mingas){  // or < ?
                mingas = curr;
                mingasidx = i;
            }
        }
        if (curr < 0){
            return -1;
        }
        return (mingasidx + 1) % n;
    }
};
