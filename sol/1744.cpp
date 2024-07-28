using BigInt = unsigned long long int;

struct Solution {
    vector<bool> canEat(const vector<int>& candiesCount, const vector<vector<int>>& queries) {
        vector<BigInt> firstIdxOfType;
        firstIdxOfType.resize(candiesCount.size() + 1);
        firstIdxOfType[0] = 0;
        for (size_t i = 0; i < candiesCount.size(); ++i){
            firstIdxOfType[i + 1] = firstIdxOfType[i] + candiesCount[i];
        }
        vector<bool> res;
        res.resize(queries.size());
        for (size_t i = 0; i < queries.size(); ++i){
            const int &candy = queries[i][0], &day = queries[i][1], &cap = queries[i][2];
            if (day >= firstIdxOfType[candy + 1]){
                res[i] = false;
            } else {
                BigInt prod = static_cast<BigInt>(day + 1) * cap;
                res[i] = prod >= firstIdxOfType[candy] + 1;
            }
        }
        return res;
    }
};
