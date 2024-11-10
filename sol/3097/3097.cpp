struct Solution {
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0){
            return 1;
        }
        int n = nums.size(), freq[32] = {0}, val = 0, res = n + 1, e = -1, x, ptr, m;
        for (int s = 0; s < n; ++s){
            while (e < n - 1 && val < k){
                x = nums[++e];
                ptr = 0;
                m = 1;
                while (x >= m){
                    if ((x & m) != 0 && (freq[ptr]++ == 0)){
                        val |= m;
                    }
                    ++ptr;
                    m <<= 1;
                }
            }
            if (val >= k){
                res = min(res, e - s + 1);
            }
            x = nums[s];
            ptr = 0;
            m = 1;
            while (x >= m){
                if ((x & m) != 0 && (--freq[ptr] == 0)){
                    val ^= m;
                }
                ++ptr;
                m <<= 1;
            }
        }
        return res > n ? -1 : res;
    }
};
