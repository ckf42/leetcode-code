struct Solution {
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), count = 0;
        bool seen[101] = {false};
        for (int i = n - 1; i >= 0; --i){
            if (seen[nums[i]]){
                break;
            }
            seen[nums[i]] = true;
            ++count;
        }
        return (n - count + 2) / 3;
    }
};
