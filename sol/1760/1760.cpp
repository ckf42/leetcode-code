struct Solution {
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1, e = 1e9 + 1;
        while (s < e){
            int m = (s + e) / 2, count = 0;
            for (int x : nums){
                count += (x - 1) / m;
            }
            if (count <= maxOperations){
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};
