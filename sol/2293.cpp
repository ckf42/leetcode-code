struct Solution {
    int alterMin(int s, int e, const vector<int> &nums){
        if (s + 1 == e){
            return nums[s];
        } else {
            return min(alterMin(s, (s + e) / 2, nums), alterMax((s + e) / 2, e, nums));
        }
    }

    int alterMax(int s, int e, const vector<int> &nums){
        if (s + 1 == e){
            return nums[s];
        } else {
            return max(alterMin(s, (s + e) / 2, nums), alterMax((s + e) / 2, e, nums));
        }
    }

    int minMaxGame(const vector<int>& nums) {
        return this->alterMin(0, nums.size(), nums);
    }
};
