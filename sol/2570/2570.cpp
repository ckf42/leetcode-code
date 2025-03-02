struct Solution {
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size(), ptr1 = 0, ptr2 = 0;
        while (ptr1 < n1 && ptr2 < n2){
            while (ptr2 < n2 && nums2[ptr2][0] < nums1[ptr1][0]){
                res.push_back(nums2[ptr2++]);
            }
            res.push_back(nums1[ptr1++]);
            while (ptr2 < n2 && nums2[ptr2][0] == res.back()[0]){
                res.back()[1] += nums2[ptr2++][1];
            }
        }
        while (ptr1 < n1){
            res.push_back(nums1[ptr1++]);
        }
        while (ptr2 < n2){
            res.push_back(nums2[ptr2++]);
        }
        return res;
    }
};
