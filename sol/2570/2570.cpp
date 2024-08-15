struct Solution {
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int l1 = nums1.size(), l2 = nums2.size(), ptr1 = 0, ptr2 = 0;
        while (ptr1 < l1 && ptr2 < l2){
            if (nums1[ptr1][0] == nums2[ptr2][0]){
                res.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ++ptr1; ++ptr2;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]){
                res.push_back(nums1[ptr1++]);
            } else {
                res.push_back(nums2[ptr2++]);
            }
        }
        while (ptr1 < l1){
            res.push_back(nums1[ptr1++]);
        }
        while (ptr2 < l2){
            res.push_back(nums2[ptr2++]);
        }
        return res;
    }
};
