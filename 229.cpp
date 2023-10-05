struct Solution {
    vector<int> majorityElement(const vector<int>& nums) {
        int items[2] = {1000000001, 1000000001}, votes[2] = {0, 0};
        for (const int &n : nums){
            if (n == items[0]){
                ++votes[0];
            } else if (n == items[1]){
                ++votes[1];
            } else if (votes[0] == 0){
                items[0] = n;
                votes[0] = 1;
            } else if (votes[1] == 0){
                items[1] = n;
                votes[1] = 1;
            } else {
                --votes[0];
                --votes[1];
            }
        }
        int realCount[2] = {0, 0};
        for (const int &n : nums){
            if (n == items[0]){
                ++realCount[0];
            } else if (n == items[1]){
                ++realCount[1];
            }
        }
        vector<int> res;
        if (realCount[0] > nums.size() / 3){
            res.push_back(items[0]);
        }
        if (realCount[1] > nums.size() / 3){
            res.push_back(items[1]);
        }
        return res;
    }
};
