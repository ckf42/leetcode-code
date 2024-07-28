struct Solution {
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ranges::sort(happiness, std::greater{});
        long long res = 0;
        int diff;
        for (int i = 0; i < k; ++i){
            diff = happiness[i] - i;
            if (diff > 0){
                res += diff;
            } else {
                break;
            }
        }
        return res;
    }
};
