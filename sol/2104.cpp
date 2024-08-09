struct Solution {
    using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<ll> memo(n, 0);
        memo[0] = nums[0];
        vector<int> st(1, 0);
        ll res = 0;
        for (int i = 1; i < n; ++i){
            while (!st.empty() && nums[st.back()] < nums[i]){
                st.pop_back();
            }
            if (st.empty()){
                memo[i] = static_cast<ll>(i + 1) * nums[i];
            } else {
                int j = st.back();
                memo[i] = memo[j] + static_cast<ll>(i - j) * nums[i];
            }
            st.push_back(i);
            res += memo[i];
        }
        st.clear();
        st.push_back(0);
        for (int i = 1; i < n; ++i){
            while (!st.empty() && nums[st.back()] > nums[i]){
                st.pop_back();
            }
            if (st.empty()){
                memo[i] = static_cast<ll>(i + 1) * nums[i];
            } else {
                int j = st.back();
                memo[i] = memo[j] + static_cast<ll>(i - j) * nums[i];
            }
            st.push_back(i);
            res -= memo[i];
        }
        return res;
    }
};
