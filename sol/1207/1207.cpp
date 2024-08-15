struct Solution {
    bool uniqueOccurrences(vector<int>& arr) {
        int counter[2000 + 1] = {0};
        bool occur[1000 + 1] = {false};
        for (int n : arr){
            ++counter[n + 1000];
        }
        for (int i = 0; i < 2000 + 1; ++i){
            if (counter[i] == 0){
                continue;
            }
            if (occur[counter[i]]){
                return false;
            }
            occur[counter[i]] = true;
        }
        return true;
    }
};
