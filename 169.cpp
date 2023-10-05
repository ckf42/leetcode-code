struct Solution {
    int majorityElement(const vector<int>& nums) {
        int top = 1e9 + 1;
        unsigned vote = 0;
        for (const int n : nums){
            if (top == n){
                ++vote;
            } else if (vote == 0){
                top = n;
                vote = 1;
            } else {
                --vote;
            }
        }
        return top;
    }
};
