struct Solution {
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> buff;
        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                buff.push_back(nums[i] * nums[j]);
            }
        }
        ranges::sort(buff);
        int m = buff.size(), res = 0, s = 0;
        while (s < m){
            int e = s + 1;
            while (e < m && buff[e] == buff[s]){
                ++e;
            }
            res += (e - s) * (e - s - 1) * 4;
            s = e;
        }
        return res;
    }
};
