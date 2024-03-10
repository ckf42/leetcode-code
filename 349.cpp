struct Solution {
    inline vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool exist[1001] = {0};
        for (int &n : nums1){
            exist[n] = true;
        }
        vector<int> res;
        for (int &n : nums2){
            if (exist[n]){
                res.push_back(n);
                exist[n] = false;
            }
        }
        return res;
    }
};
