struct Solution {
    vector<int> getAverages(const vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<int> res(n, -1);
        size_t segLen = k * 2 + 1;
        if (n < segLen){
            return res;
        }
        long winSum = 0;
        for (vector<int>::const_iterator it = nums.cbegin();
            it != nums.cbegin() + segLen;
             ++it){
            winSum += *it;
        }
        res[k] = static_cast<int>(winSum / segLen);
        for (size_t idx = k + 1; idx < n - k; ++idx){
            winSum += nums.at(idx + k) - nums.at(idx - k - 1);
            res.at(idx) = static_cast<int>(winSum / segLen);
        }
        return res;
    }
};
