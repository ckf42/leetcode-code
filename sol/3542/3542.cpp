struct Solution {
    int minOperations(vector<int>& nums) {
        int res = 0;
        vector<int> st(1, 0);
        for (int x : nums){
            while (st.back() > x){
                ++res;
                st.pop_back();
            }
            if (st.back() != x){
                st.push_back(x);
            }
        }
        res += st.size() - 1;
        return res;
    }
};
