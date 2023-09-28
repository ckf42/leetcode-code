struct Solution {
    bool checkDistances(const string& s, const vector<int>& distance) {
        short indices[26] = {0}, sa;
        for (short i = 0; i < s.size(); ++i){
            sa = s[i] - 'a';
            if (indices[sa] == 0){
                indices[sa] = i + 1;
            } else if (i - indices[sa] != distance[sa]){
                return false;
            }
        }
        return true;
    }
};
