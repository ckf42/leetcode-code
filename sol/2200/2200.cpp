struct Solution {
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> indices, res;
        for (int i = 0; i < n; ++i){
            if (nums[i] == key){
                indices.push_back(i);
            }
        }
        int l = indices.size(), ptr = -1;
        for (int i = 0; i < n; ++i){
            while (ptr < l - 1 && indices[ptr + 1] <= i + k){
                ++ptr;
            }
            if (ptr != -1 && i - indices[ptr] <= k){
                res.push_back(i);
            }
        }
        return res;
    }
};
