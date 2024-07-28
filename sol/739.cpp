struct Solution {
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), idx;
        vector<int> ans(n, 0), st;
        for (int i = 0; i < n; ++i){
            while (!st.empty() && temperatures[i] > temperatures[st.back()]){
                idx = st.back();
                st.pop_back();
                ans[idx] = i - idx;
            }
            st.push_back(i);
        }
        return ans;
    }
};
