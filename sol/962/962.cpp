struct Solution {
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> st;
        for (int i = 0; i < n; ++i){
            if (st.empty() || nums[st.back()] > nums[i]){
                st.push_back(i);
            }
        }
        for (int j = n - 1; j >= 0; --j){
            while (!st.empty() && nums[st.back()] <= nums[j]){
                res = max(res, j - st.back());
                st.pop_back();
            }
        }
        return res;
    }
};
