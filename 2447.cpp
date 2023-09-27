struct Solution {
    int gcd(int a, int b){
        if (a == b){ // one less mod
            return a;
        }
        return b == 0 ? a : this->gcd(b, a % b);
    }

    int subarrayGCD(const vector<int>& nums, int k) {
        int count = 0, g;
        size_t n = nums.size(), i, j;
        for (i = 0; i < n; ++i){
            g = nums[i];
            if (g == k){
                ++count;
            } else if (g % k != 0){
                continue;
            }
            for (j = i + 1; j < n; ++j){
                g = this->gcd(g, nums[j]);
                if (g == k){
                    ++count;
                } else if (g % k != 0){
                    break;
                }
            }
        }
        return count;
    }
};
