struct Solution {
    static constexpr int m = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> memo(n, 0);
        memo[0] = arr[0];
        vector<int> st(1, 0);
        int res = arr[0];
        for (int i = 1; i < n; ++i){
            while (!st.empty() && arr[st.back()] > arr[i]){
                st.pop_back();
            }
            if (st.empty()){
                memo[i] = ((i + 1) * arr[i]) % this->m;
            } else {
                int j = st.back();
                memo[i] = (memo[j] + ((i - j) * arr[i]) % this->m) % this->m;
            }
            st.push_back(i);
            res = (res + memo[i]) % this->m;
        }
        return res;
    }
};
