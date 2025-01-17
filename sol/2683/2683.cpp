struct Solution {
    bool doesValidArrayExist(vector<int>& derived) {
        return (reduce(derived.begin(), derived.end(), 0) & 1) == 0;
    }
};
