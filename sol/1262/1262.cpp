struct Solution {
    int maxSumDivThree(vector<int>& nums) {
        constexpr int M = 1e4 + 1;
        int mins[2][2] = {{M, M}, {M, M}};
        int count = 0, r;
        for (int x : nums){
            count += x;
            r = x % 3;
            if (r-- != 0){
                if (x <= mins[r][0]){
                    mins[r][1] = mins[r][0];
                    mins[r][0] = x;
                } else if (x <= mins[r][1]){
                    mins[r][1] = x;
                }
            }    
        }
        r = count % 3;
        if (r-- != 0){
            int opt = count;
            if (mins[r][0] != M){
                opt = mins[r][0];
            } 
            if (mins[1 - r][1] != M){
                opt = min(opt, mins[1 - r][0] + mins[1 - r][1]);
            }
            count -= opt;
        }
        return count;
    }
};
