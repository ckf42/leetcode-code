struct Solution {
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int wptr = 0, prevEle = nums[0];
        for (int i = 1; i < n; ++i){
            if (nums[i] == prevEle){
                prevEle <<= 1;
                nums[i] = 0;
            }
            if (prevEle != 0){
                res[wptr++] = prevEle;
            }
            prevEle = nums[i];
        }
        res[wptr] = prevEle;
        return res;
    }
};
