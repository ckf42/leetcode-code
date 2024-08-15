struct Solution {
    inline vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b, c = 0;
        for (int &n : nums){
            a ^= n;
        }
        b = a & (1 + ~static_cast<unsigned>(a));
        a = 0;
        for (int &n : nums){
            if (n & b){
                a ^= n;
            } else {
                c ^= n;
            }
        }
        return {a, c};
    }
};
