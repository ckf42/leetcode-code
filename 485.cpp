struct Solution {
    inline int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxseq = 0, res = 0;
        for (int x : nums){
            if (x == 0){
                res = max(res, maxseq);
                maxseq = 0;
            } else {
                ++maxseq;
            }
        }
        return max(res, maxseq);
    }
};
