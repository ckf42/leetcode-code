struct Solution {
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count[1001] = {0};
        for (int v : target){
            ++count[v];
        }
        for (int v : arr){
            --count[v];
        }
        for (int i = 1; i <= 1000; ++i){
            if (count[i] != 0){
                return false;
            }
        }
        return true;
    }
};
