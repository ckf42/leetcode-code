struct Solution {
    inline int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), wa = capacityA, wb = capacityB, refill = 0;
        int a = 0, b = n - 1;
        while (a < b){
            if (plants[a] > wa){
                ++refill;
                wa = capacityA;
            }
            wa -= plants[a++];
            if (plants[b] > wb){
                ++refill;
                wb = capacityB;
            }
            wb -= plants[b--];
        }
        if (a == b){
            refill += (plants[a] > max(wa, wb));
        }
        return refill;
    }
};
