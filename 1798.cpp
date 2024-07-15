struct Solution {
    int getMaximumConsecutive(vector<int>& coins) {
        ranges::sort(coins);
        int reach = 1;
        for (int x : coins){
            if (x > reach){
                break;
            }
            reach += x;
        }
        return reach;
    }
};
