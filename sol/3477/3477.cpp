struct Solution {
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplaced = 0;
        for (int f : fruits){
            ++unplaced;
            for (int i = 0; i < n; ++i){
                if (baskets[i] >= f){
                    baskets[i] = -1;
                    --unplaced;
                    break;
                }
            }
        }
        return unplaced;
    }
};
