struct Solution {
    inline int gcd(int a, int b){
        if (a == b){
            return a;
        }
        int temp;
        while (b != 0){
            temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
    int subarrayLCM(const vector<int>& nums, int k) {
        int count = 0, l;
        size_t n = nums.size(), i, j;
        for (i = 0; i < n; ++i){
            l = nums[i];
            if (l == k){
                ++count;
            } else if (k % l != 0){
                continue;
            }
            for (j = i + 1; j < n; ++j){
                l = l / this->gcd(l, nums[j]) * nums[j];
                if (l == k){
                    ++count;
                } else if (k % l != 0){
                    break;
                }
            }
        }
        return count;
    }
};
