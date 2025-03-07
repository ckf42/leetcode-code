struct Solution {
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), small = 0, large = 0;
        for (int x : nums){
            if (x < pivot){
                ++small;
            } else if (x > pivot){
                ++large;
            }
        }
        vector<int> res(n, pivot);
        int lptr = 0, rptr = n - large;
        for (int x : nums){
            if (x < pivot){
                res[lptr++] = x;
            } else if (x > pivot){
                res[rptr++] = x;
            }
        }
        return res;
    }
};
